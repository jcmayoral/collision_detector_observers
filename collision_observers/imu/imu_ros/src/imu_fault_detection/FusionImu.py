import rospy
from FaultDetection import ChangeDetection
from sensor_msgs.msg import Imu
from fusion_msgs.msg import sensorFusionMsg, controllerFusionMsg
import numpy as np
import math

# For PCA
from sklearn.decomposition import PCA

#Dynamic Reconfigure
from dynamic_reconfigure.server import Server
from imu_ros.cfg import imuConfig

class FusionImu(ChangeDetection):
    def __init__(self, cusum_window_size = 10, frame="base_link", sensor_id="accel1", threshold = 60):
        self.data_ = np.zeros(6)
        self.i = 0
        self.msg = 0
        self.window_size = cusum_window_size
        self.frame = frame
        self.threshold = np.ones(3) * threshold
        self.weight = 1.0
        self.is_disable = False
        self.is_filtered_available = False
        self.is_collision_expected = False
        self.is_over_lapping_required = False
        self.is_covariance_detector_enable = False
        self.old_angle = 0

        ChangeDetection.__init__(self,6,10)

        rospy.init_node("imu_fusion", anonymous=False)
        sensor_number = rospy.get_param("~sensor_number", 0)
        self.pub = rospy.Publisher('collisions_'+ str(sensor_number), sensorFusionMsg, queue_size=10)
        self.sensor_id = rospy.get_param("~sensor_id", sensor_id)
        self.dyn_reconfigure_srv = Server(imuConfig, self.dynamic_reconfigureCB)
        rospy.loginfo("Imu Ready for Fusion")
        input_topic = rospy.get_param("~input_topic", "/imu/data")
        print(input_topic)
        rospy.Subscriber(input_topic, Imu, self.imuCB)
        self.subscriber_ = rospy.Subscriber("filter", controllerFusionMsg, self.filterCB)

        rospy.spin()

    def filterCB(self, msg):
        if msg.mode is controllerFusionMsg.IGNORE:
            self.is_collision_expected = True
            #rospy.sleep(0.05) # TODO
        else:
            self.is_collision_expected = False

    def reset_publisher(self):
        self.pub = rospy.Publisher('collisions_'+ str(self.sensor_number), sensorFusionMsg, queue_size=10)


    def dynamic_reconfigureCB(self,config, level):
        self.threshold[0] = config["x_threshold"]
        self.threshold[1] = config["y_threshold"]
        self.threshold[2] = config["z_threshold"]
        self.window_size = config["window_size"]
        self.weight = config["weight"]
        self.is_disable = config["is_disable"]
        self.sensor_number = config["detector_id"]
        self.is_filtered_available = config["is_filter"]
        self.is_over_lapping_required = config["overlap"]
        self.is_covariance_detector_enable = config["covariance_detector"]

        self.reset_publisher()

        if config["reset"]:
            self.clear_values()
            config["reset"] = False

        return config

    def imuCB(self, msg):

        if self.is_over_lapping_required:
            self.addData([msg.linear_acceleration.x, msg.linear_acceleration.y, msg.linear_acceleration.z,#]), #]) #Just Linear For Testing
                msg.angular_velocity.x, msg.angular_velocity.y, msg.angular_velocity.z]) #Angula
            while len(self.samples) > self.window_size:
                self.samples.pop(0)

        else:
            if ( self.i < self.window_size) and len(self.samples) < self.window_size:
                self.addData([msg.linear_acceleration.x, msg.linear_acceleration.y, msg.linear_acceleration.z,#])#, #]) #Just Linear For Testing
                msg.angular_velocity.x, msg.angular_velocity.y, msg.angular_velocity.z]) #Angula
                self.i = self.i+1

                if len(self.samples) is self.window_size:
                    self.samples.pop(0)
                return

        output_msg = sensorFusionMsg()
        self.i=0
        self.changeDetection(len(self.samples))

        cur = np.array(self.cum_sum, dtype = object)
        #Filling Message
        output_msg.header.frame_id = self.frame
        output_msg.window_size = self.window_size
        covariance = np.var(cur)

        #current_angle = math.atan2(self.samples[-1][1] - self.samples[-2][1],self.samples[-2][0] - self.samples[-1][0])
        #output_msg.angle = current_angle

        output_msg.header.stamp = rospy.Time.now()
        output_msg.sensor_id.data = self.sensor_id
        output_msg.data = cur
        output_msg.weight = self.weight


        if self.is_covariance_detector_enable:
            if any(covariance > self.threshold):
                rospy.logwarn(covariance)
                rospy.logwarn(cur > self.threshold)
                output_msg.msg = sensorFusionMsg.ERROR

                if self.is_collision_expected and self.is_filtered_available:
                    print ("Colliison Filtered")
                    output_msg.msg = sensorFusionMsg.WARN
                    self.is_collision_expected = False
                if not self.is_disable:
                    self.pub.publish(output_msg)
        else:
            print ("here", cur[0:3])

            if any(cur[0:3] > self.threshold):
                print ("here2")
                rospy.logwarn(cur)
                if cur[5] > self.threshold[2]:
                    rospy.logwarn("Angle")
                x,y,z = (cur[0:3] > self.threshold)

                if x and not y:
                    print("NORTH")

                if not x and y:
                    print("EAST")
                if x and y:
                    print ("NE")

                output_msg.msg = sensorFusionMsg.ERROR

                if self.is_collision_expected and self.is_filtered_available:
                    print ("Colliison Filtered")
                    output_msg.msg = sensorFusionMsg.WARN
                    self.is_collision_expected = False

                if not self.is_disable:
                    self.pub.publish(output_msg)
