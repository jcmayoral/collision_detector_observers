import rospy
from FaultDetection import ChangeDetection
from geometry_msgs.msg import AccelStamped
from fusion_msgs.msg import sensorFusionMsg
import numpy as np

class FusionAcc(ChangeDetection):
    def __init__(self, cusum_window_size = 10 ):
        self.data_ = []
        self.data_.append([0,0,0])
        self.i = 0
        self.msg = 0
        self.window_size = cusum_window_size
        ChangeDetection.__init__(self,10)
        rospy.init_node("accelerometer_cusum", anonymous=True)
        rospy.Subscriber("accel", AccelStamped, self.accCB)
        self.pub = rospy.Publisher('collisions_1', sensorFusionMsg, queue_size=10)
        rospy.spin()

    def accCB(self, msg):
        while (self.i< self.window_size):
            self.addData([msg.accel.linear.x,msg.accel.linear.y, msg.accel.angular.z])
            self.i = self.i+1
            if len(self.samples) is self.window_size:
                self.samples.pop(0)
            return
        self.i=0
        self.changeDetection(len(self.samples))
        cur = np.array(self.cum_sum, dtype = object)
        msg = sensorFusionMsg()
        msg.data = cur
        self.pub.publish(msg)
