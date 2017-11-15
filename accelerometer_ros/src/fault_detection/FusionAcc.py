import rospy
from FaultDetection import ChangeDetection
from geometry_msgs.msg import AccelStamped
from fusion_msgs.msg import sensorFusionMsg
import numpy as np

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
        ChangeDetection.__init__(self)
        rospy.init_node("accelerometer_fusion", anonymous=False)
        rospy.Subscriber("accel", AccelStamped, self.accCB)
        self.pub = rospy.Publisher('collisions_0', sensorFusionMsg, queue_size=10)
        self.dyn_reconfigure_srv = Server(accelerometerConfig, self.dynamic_reconfigureCB)
        rospy.spin()

    def dynamic_reconfigureCB(self,config, level):
        self.threshold = config["threshold"]
        self.window_size = config["window_size"]
        return config

    def accCB(self, msg):
        while (self.i< self.window_size):
            self.addData([msg.accel.linear.x,msg.accel.linear.y, msg.accel.angular.z])
            self.i = self.i+1
            if len(self.samples) is self.window_size:
                self.samples.pop(0)
            return

        msg = sensorFusionMsg()

        self.i=0
        self.changeDetection(len(self.samples))


        cur = np.array(self.cum_sum, dtype = object)
        #Filling Message
        msg.header.frame_id = self.frame
        msg.window_size = self.window_size

        #Detecting Collisions
        if any(t > self.threshold for t in cur):
            msg.msg = sensorFusionMsg.ERROR

        msg.header.stamp = rospy.Time.now()
        msg.sensor_id.data = self.sensor_id
        msg.data = cur
        self.pub.publish(msg)
