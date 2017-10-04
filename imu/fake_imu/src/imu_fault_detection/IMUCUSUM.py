import rospy
from MyStatics.RealTimePlotter import RealTimePlotter
from sensor_msgs.msg import Imu
import numpy as np
import matplotlib
matplotlib.use('TkAgg')
from FaultDetection import ChangeDetection
import matplotlib.pyplot as plt


class IMUCUSUM(RealTimePlotter,ChangeDetection):
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
        rospy.init_node("imu_cusum", anonymous=True)
        rospy.Subscriber("imu", Imu, self.imuCB)
        plt.legend()
        plt.show()
        rospy.spin()
        plt.close("all")

    def imuCB(self, msg):
        while (self.i< self.window_size):
            self.addData([msg.linear_acceleration.x,msg.linear_acceleration.y, msg.angular_velocity.z])
            self.i = self.i+1
            if len(self.samples) is self.max_samples:
                self.samples.pop(0)
            return
        self.i=0
        self.changeDetection(len(self.samples))
        cur = np.array(self.cum_sum, dtype = object)
        self.step_.append(self.msg)
        self.data_.append(cur)
        self.msg = self.msg + 1
        self.update(msg.header.seq,self.step_,self.data_)
