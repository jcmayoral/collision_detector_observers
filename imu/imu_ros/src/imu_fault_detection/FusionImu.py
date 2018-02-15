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
        self.data_ = []
        self.data_.append([0,0,0,0,0,0])
        self.i = 0
        self.msg = 0
        self.window_size = cusum_window_size
        self.frame = frame
        self.threshold = threshold
        self.weight = 1.0
        self.is_disable = False
        self.is_filtered_available = False
        self.is_collision_expected = False

        ChangeDetection.__init__(self,6)
        rospy.init_node("imu_fusion", anonymous=False)
        rospy.Subscriber("imu/data", Imu, self.imuCB)
        self.subscriber_ = rospy.Subscriber("filter", controllerFusionMsg, self.filterCB)
        sensor_number = rospy.get_param("~sensor_number", 0)
        self.sensor_id = rospy.get_param("~sensor_id", sensor_id)
        self.pub = rospy.Publisher('collisions_'+ str(sensor_number), sensorFusionMsg, queue_size=10)
        self.dyn_reconfigure_srv = Server(imuConfig, self.dynamic_reconfigureCB)
        rospy.loginfo("Imu Ready for Fusion")
        rospy.spin()

    def filterCB(self, msg):
        if msg.mode is controllerFusionMsg.IGNORE:
            self.is_collision_expected = True
            print ("here")
            #rospy.sleep(0.05) # TODO
        else:
            self.is_collision_expected = False

    def reset_publisher(self):
        self.pub = rospy.Publisher('collisions_'+ str(self.sensor_number), sensorFusionMsg, queue_size=10)


    def dynamic_reconfigureCB(self,config, level):
        self.threshold = config["threshold"]
        self.window_size = config["window_size"]
        self.weight = config["weight"]
        self.is_disable = config["is_disable"]
        self.sensor_number = config["detector_id"]
        self.is_filtered_available = config["is_filter"]

        self.reset_publisher()

        if config["reset"]:
            self.clear_values()
            config["reset"] = False

        return config

    def imuCB(self, msg):

        self.addData([msg.linear_acceleration.x, msg.linear_acceleration.y, msg.linear_acceleration.z, #]) #Just Linear For Testing
                      msg.angular_velocity.x, msg.angular_velocity.y, msg.angular_velocity.z]) #Angular

        if len(self.samples) > self.window_size:
            self.samples.pop(0)

        output_msg = sensorFusionMsg()

        current_mean = np.mean(self.samples, axis=0)
        #print (current_mean)
        tmp = (np.array(self.last_mean) - np.array(current_mean))
        x,y,z,gx,gy,gz = 9.81 * (tmp/255) * 2
        magnitude = np. sqrt(np.power(x,2) + np.power(y,2) + np.power(z,2))
        #print ("magnitude ", magnitude)
        #print (np.arccos(x/magnitude), np.arccos(y/magnitude), np.arccos(z/magnitude))
        output_msg.angle = np.arctan2(y,x)#np.arccos(x/magnitude)#np.arctan2(y,x)
        #Detecting Collisions

        self.i=0
        self.changeDetection(len(self.samples))

        cur = np.array(self.cum_sum, dtype = object)
        #Filling Message
        output_msg.header.frame_id = self.frame
        output_msg.window_size = self.window_size
        print ("Accelerations " , x,y,z)

        if any(t > self.threshold for t in cur if not math.isnan(t) and t < 1000):
            output_msg.msg = sensorFusionMsg.ERROR
            print ("Collision")
            print (np.degrees(np.arccos(x/magnitude)), np.degrees(np.arccos(y/magnitude)), np.degrees((np.arccos(z/magnitude))))
            print (np.degrees(np.arctan2(y,x)))
            if self.is_collision_expected and self.is_filtered_available:
                print ("Colliison Filtered")
                output_msg.msg = sensorFusionMsg.WARN
                self.is_collision_expected = False
            #print np.degrees(np.arctan2(diff[1],diff[0]))
            #For Testing


        """
        #TODO FOR PCA
        pca = PCA(n_components=2)
        pca.fit(self.samples)
        pca = pca.transform(self.samples)

        #print(pca.components_)
        print(pca.explained_variance_ratio_)
        print ("New:")
        current_angle = np.degrees(np.arctan2(pca.explained_variance_ratio_[0],pca.explained_variance_ratio_[1]))
        #current_angle = np.degrees(np.arctan2(cur[1],cur[0]))
        msg.angle = current_angle - self.last_angle
        self.last_angle = current_angle

        print (pca.explained_variance_)
        print(np.arctan2(pca.explained_variance_[1],pca.explained_variance_[0]))
        print(pca.explained_variance_)
        """
        output_msg.header.stamp = rospy.Time.now()
        output_msg.sensor_id.data = self.sensor_id
        output_msg.data = cur
        output_msg.weight = self.weight

        if not self.is_disable:
            self.pub.publish(output_msg)
