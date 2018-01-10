import rospy
from FaultDetection import ChangeDetection
from geometry_msgs.msg import AccelStamped
from fusion_msgs.msg import sensorFusionMsg
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
        self.i = 0
        self.msg = 0
        self.window_size = cusum_window_size
        self.frame = frame
        self.sensor_id = sensor_id
        self.threshold = threshold
        self.weight = 1.0
        ChangeDetection.__init__(self)
        rospy.init_node("accelerometer_fusion", anonymous=False)
        rospy.Subscriber("accel", AccelStamped, self.accCB)
        self.pub = rospy.Publisher('collisions_0', sensorFusionMsg, queue_size=10)
        self.dyn_reconfigure_srv = Server(accelerometerConfig, self.dynamic_reconfigureCB)
        rospy.spin()

    def dynamic_reconfigureCB(self,config, level):
        self.threshold = config["threshold"]
        self.window_size = config["window_size"]
        self.weight = config["weight"]
        return config

    def accCB(self, msg):

        while (self.i< self.window_size):
            self.addData([msg.accel.linear.x,msg.accel.linear.y, msg.accel.angular.z])
            self.i = self.i+1
            if len(self.samples) is self.window_size:
                self.samples.pop(0)
            return

        output_msg = sensorFusionMsg()

        current_mean = np.mean(self.samples, axis=0)
        diff = np.round(np.array(current_mean) - np.array(self.last_mean))
        #print (diff)
        output_msg.angle = np.degrees(np.arctan2(diff[0],diff[1]))
        #Detecting Collisions

        self.i=0
        self.changeDetection(len(self.samples))

        cur = np.array(self.cum_sum, dtype = object)
        #Filling Message
        output_msg.header.frame_id = self.frame
        output_msg.window_size = self.window_size

        if any(t > self.threshold for t in cur):
            output_msg.msg = sensorFusionMsg.ERROR
            print np.degrees(np.arctan2(diff[0],diff[1]))


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
        self.pub.publish(output_msg)
