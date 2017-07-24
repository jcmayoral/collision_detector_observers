import rospy
from accelerometer_ros.RealTimePlotter import RealTimePlotter
from FaultDetection import ChangeDetection
from geometry_msgs.msg import AccelStamped
import matplotlib
matplotlib.use('TkAgg')
import matplotlib.pyplot as plt

class AccCUSUM(RealTimePlotter,ChangeDetection):
    def __init__(self, threshold = 1000, pace = 200):
        self.data_ = [0,0,0]
        self.step_ = []
        self.i = 0
        RealTimePlotter.__init__(self,threshold,pace)
        ChangeDetection.__init__(self,10)
        rospy.init_node("accelerometer_cusum", anonymous=True)
        rospy.Subscriber("accel", AccelStamped, self.accCB)
        plt.show()
        rospy.spin()
        plt.close("all")

    def accCB(self, msg):
        while (self.i<10):
            self.addData([msg.accel.linear.x,msg.accel.linear.y, msg.accel.angular.z])
            self.i = self.i+1
            if len(self.samples) is self.threshold_:
                self.samples.pop(0)
            return
        self.i=0
        self.changeDetection()
        self.step_.append(msg.header.seq)
        print(self.cum_sum)
        self.data_.append([self.cum_sum[0],self.cum_sum[1],self.cum_sum[2]])
        self.update(msg.header.seq,self.step_,self.data_)
