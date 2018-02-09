import rospy
from FaultDetection import ChangeDetection
from geometry_msgs.msg import AccelStamped
from fusion_msgs.msg import sensorFusionMsg, controllerFusionMsg
import numpy as np

# For PCA
from sklearn.decomposition import PCA

#Dynamic Reconfigure
from dynamic_reconfigure.server import Server
from accelerometer_ros.cfg import accelerometerConfig

class FusionAcc(ChangeDetection):
    def __init__(self, cusum_window_size = 10, frame="base_link", sensor_id="accel1", threshold = 60):
        self.data_ = []
        self.data_.append([0,0,0])
        self.msg = 0
        self.window_size = cusum_window_size
        self.frame = frame
        self.threshold = threshold
        self.weight = 1.0
        self.is_disable = False
        self.is_filtered_available = False
        self.is_collision_expected = False

        ChangeDetection.__init__(self)
        rospy.init_node("accelerometer_fusion", anonymous=False)
        self.subscriber_ = rospy.Subscriber("accel", AccelStamped, self.accCB)
        self.subscriber_ = rospy.Subscriber("filter", controllerFusionMsg, self.filterCB)

        sensor_number = rospy.get_param("~sensor_number", 0)
        self.sensor_id = rospy.get_param("~sensor_id", sensor_id)
        self.pub = rospy.Publisher('collisions_'+ str(sensor_number), sensorFusionMsg, queue_size=10)
        self.dyn_reconfigure_srv = Server(accelerometerConfig, self.dynamic_reconfigureCB)
        rospy.loginfo("Accelerometer Ready for Fusion")
        rospy.spin()

    def filterCB(self, msg):
        if msg.mode is controllerFusionMsg.IGNORE:
            self.is_collision_expected = True
        else:
            self.is_collision_expected = False
        rospy.sleep(0.1)

    def reset_publisher(self):
        self.pub = rospy.Publisher('collisions_'+ str(self.sensor_number), sensorFusionMsg, queue_size=10)

    def reset_subscriber(self):
        self.subscriber_.unregister()

        if self.is_filtered_available:
            self.subscriber_ = rospy.Subscriber("accel", filteredAccCB, self.accCB)
        else:
            self.subscriber_ = rospy.Subscriber("accel", AccelStamped, self.accCB)

    def dynamic_reconfigureCB(self,config, level):
        self.threshold = config["threshold"]
        self.window_size = config["window_size"]
        self.weight = config["weight"]
        self.is_disable = config["is_disable"]
        self.sensor_number = config["detector_id"]
        self.is_filtered_available = config["is_filter"]

        self.reset_publisher()
        self.reset_subscriber()

        if config["reset"]:
            self.clear_values()
            config["reset"] = False
        return config

    def filteredAccCB(self, msg):
        self.addData([msg.accel.linear.x,msg.accel.linear.y, msg.accel.angular.z])

        if ( len(self.samples) > self.window_size):
            self.samples.pop(0)

        output_msg = sensorFusionMsg()

        self.changeDetection(len(self.samples))

        cur = np.array(self.cum_sum, dtype = object)

        #Filling Message
        output_msg.header.frame_id = self.frame
        output_msg.window_size = self.window_size
        #print ("Accelerations " , x,y,z)

        if any(t > self.threshold for t in cur):
            output_msg.msg = sensorFusionMsg.ERROR
            print ("Collision")

        output_msg.header.stamp = rospy.Time.now()
        output_msg.sensor_id.data = self.sensor_id
        output_msg.data = cur
        output_msg.weight = self.weight

        if not self.is_disable and is_collision_expected:
            self.pub.publish(output_msg)

    def accCB(self, msg):
        self.addData([msg.accel.linear.x,msg.accel.linear.y, msg.accel.angular.z])

        if ( len(self.samples) > self.window_size):
            self.samples.pop(0)

        output_msg = sensorFusionMsg()

        current_mean = np.mean(self.samples, axis=0)
        #print (current_mean)
        tmp = (np.array(self.last_mean) - np.array(current_mean))
        x,y,z = 9.81 * (tmp/255) * 2
        magnitude = np. sqrt(np.power(x,2) + np.power(y,2) + np.power(z,2))
        #print ("magnitude ", magnitude)
        #print (np.arccos(x/magnitude), np.arccos(y/magnitude), np.arccos(z/magnitude))
        output_msg.angle = np.arctan2(y,x)#np.arccos(x/magnitude)#np.arctan2(y,x)
        #Detecting Collisions

        self.changeDetection(len(self.samples))

        cur = np.array(self.cum_sum, dtype = object)
        #Filling Message
        output_msg.header.frame_id = self.frame
        output_msg.window_size = self.window_size
        #print ("Accelerations " , x,y,z)

        if any(t > self.threshold for t in cur):
            output_msg.msg = sensorFusionMsg.ERROR
            print ("Collision")
            print (np.degrees(np.arccos(x/magnitude)), np.degrees(np.arccos(y/magnitude)), np.degrees((np.arccos(z/magnitude))))
            print (np.degrees(np.arctan2(y,x)))
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
