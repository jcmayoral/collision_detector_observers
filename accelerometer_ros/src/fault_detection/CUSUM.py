import rospy
from FaultDetection import ChangeDetection
from accelerometer_ros.RealTimePlotter import RealTimePlotter
from geometry_msgs.msg import AccelStamped
import matplotlib
matplotlib.use('TkAgg')
import matplotlib.pyplot as plt

class CUSUM(RealTimePlotter):
    def __init__(self, threshold = 1000, pace = 200, seconds=1):
        super().__init__(threshold,pace)
        rospy.init_node("accelerometer_cusum", anonymous=True)
        self.fd = ChangeDetection(seconds)
        self.seq =[]
        self.data =[]
        self.count = 0
        rospy.Subscriber("accel", AccelStamped, self.run)
        plt.show()
        rospy.spin()
        plt.close("all")

    def run(self,msg):
        self.fd.samples.append([msg.accel.linear.x,msg.accel.linear.y,msg.accel.angular.z])

        if self.count is 1:
            self.seq.append(msg.header.seq)
            self.fd.changeDetection()
            self.data.append(self.fd.cum_sum)
            print (self.fd.cum_sum)
            self.update(msg.header.seq,self.seq,self.data)
            self.count = 0

        self.count = self.count + 1
