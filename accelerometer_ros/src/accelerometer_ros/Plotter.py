import rospy
import matplotlib
matplotlib.use('TkAgg')
import matplotlib.pyplot as plt
import time
from geometry_msgs.msg import AccelStamped

class Plotter:
    def __init__(self, threshold = 1000):
        rospy.init_node("accelerometer_plotter", anonymous=True)
        self.data_ = []
        self.step_ = []
        self.threshold_ = threshold
        self.f, self.ax = plt.subplots()
        self.ax.set_title('Simple plot')
        rospy.Subscriber("accel", AccelStamped, self.accCB)
        print ("Plotter Constructor Initialized")
        #self.anim_ = FuncAnimation(self._, self.data_, range(len(self.data_)), interval=10, repeat=False)
        plt.show()
        rospy.spin()
        rospy.on_shutdown(self.stop())

    def stop(self):
        plt.close("all")

    def accCB(self, msg):
        self.step_.append(msg.header.seq)
        self.data_.append([msg.accel.linear.x,msg.accel.linear.y, msg.accel.angular.z])
        plt.draw()
        if msg.header.seq % self.threshold_ is 0:
            print ("Threshold reached")
            self.ax.plot(self.step_, self.data_)
        #self.ax_.plot(self.step_,self.data_)
        #plt.draw()
        #del self.step_[:]
        #del self.data_[:]
        #self.f_.show()