import rospy
import time
from accelerometer_ros.RealTimePlotter import RealTimePlotter
from geometry_msgs.msg import AccelStamped
import matplotlib
matplotlib.use('TkAgg')
import matplotlib.pyplot as plt

class Plotter(RealTimePlotter):
    def __init__(self, threshold = 1000, pace = 200):
        self.data_ = []
        self.step_ = []
        print ("Plotter Constructor Initialized")
        super().__init__(threshold,pace)
        rospy.init_node("accelerometer_plotter", anonymous=True)
        print('a')
        rospy.Subscriber("accel", AccelStamped, self.accCB)
        print('a')
        plt.show()
        print('a')
        rospy.spin()
        rospy.on_shutdown(self.stop)

    def accCB(self, msg):
        print ("msg")
        self.step_.append(msg.header.seq)
        self.data_.append([msg.accel.linear.x,msg.accel.linear.y, msg.accel.angular.z])
        self.update(msg.header.seq,self.step_,self.data_)
