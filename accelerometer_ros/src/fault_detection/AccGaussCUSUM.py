import rospy
from MyStatics.RealTimePlotter import RealTimePlotter
from MyStatics.GaussianPlotter import GaussPlot
from FaultDetection import ChangeDetection
from geometry_msgs.msg import AccelStamped
import numpy as np
import matplotlib
matplotlib.use('TkAgg')
import matplotlib.pyplot as plt


class AccGaussCUSUM(RealTimePlotter,ChangeDetection,GaussPlot):
    def __init__(self, max_samples = 500, pace = 2, cusum_window_size = 10 ):
        self.data_ = []
        self.data_.append([0,0,0])
        self.step_ = []
        self.step_.append(0)
        self.i = 0
        self.msg = 0
        self.window_size = cusum_window_size
        RealTimePlotter.__init__(self,max_samples,pace)
        ChangeDetection.__init__(self,10)
        GaussPlot.__init__(self )
        rospy.init_node("accelerometer_cusum", anonymous=True)
        rospy.Subscriber("accel", AccelStamped, self.accCB)
        plt.legend()
        plt.show()
        rospy.spin()
        plt.close("all")

    def accCB(self, msg):
        while (self.i< self.window_size):
            self.addData([msg.accel.linear.x,msg.accel.linear.y, msg.accel.angular.z])
            self.i = self.i+1
            if len(self.samples) is self.max_samples:
                self.samples.pop(0)
            return
        self.i=0
        self.changeDetection(len(self.samples))
        cur = np.array(self.cum_sum, dtype = object)
        self.call(self.s_z,np.mean(self.samples, axis=0),np.var(self.samples, axis=0))
        self.step_.append(self.msg)
        self.data_.append(cur)
        self.msg = self.msg + 1
        self.update(msg.header.seq,self.x,self.rv.pdf(self.x))
