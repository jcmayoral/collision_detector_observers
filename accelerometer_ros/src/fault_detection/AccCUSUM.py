import rospy
from accelerometer_ros.RealTimePlotter import RealTimePlotter
from FaultDetection import ChangeDetection
from geometry_msgs.msg import AccelStamped
import numpy as np
import matplotlib
matplotlib.use('TkAgg')
import matplotlib.pyplot as plt

class AccCUSUM(RealTimePlotter,ChangeDetection):
    def __init__(self, max_samples = 50, pace = 200, window_size = ):
        self.data_ = []
        self.step_ = []
        self.i = 0
        self.msg = 0
        RealTimePlotter.__init__(self,max_samples,pace)
        ChangeDetection.__init__(self,10)
        rospy.init_node("accelerometer_cusum", anonymous=True)
        rospy.Subscriber("accel", AccelStamped, self.accCB)
        plt.show()
        rospy.spin()
        plt.close("all")

    def accCB(self, msg):
        while (self.i< self.window_size):
            self.addData([msg.accel.linear.x,msg.accel.linear.y, msg.accel.angular.z])
            self.i = self.i+1
            if len(self.samples) is self.threshold_:
                self.samples.pop(0)
            return
        self.i=0
        self.changeDetection()
        cur = np.array(self.cum_sum, dtype = object)
        self.step_.append(self.msg)
        self.data_.append(cur)
        self.msg = self.msg + 1
        self.update(msg.header.seq,self.step_,self.data_)
