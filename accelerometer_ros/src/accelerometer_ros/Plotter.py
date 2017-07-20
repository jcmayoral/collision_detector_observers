import rospy
import numpy as np
import matplotlib.pyplot as plt
from geometry_msgs.msg import AccelStamped

class Plotter:
    def __init__(self, threshold = 1000):
        rospy.init_node("accelerometer_plotter", anonymous=True)
        self.data_ = []
        rospy.Subscriber("accel", AccelStamped, self.accCB)
        self.step_ = []
        self.threshold_ = threshold
        print ("Plotter Constructor Initialized")
        rospy.spin()

    def accCB(self, msg):
        self.step_.append(msg.header.seq)
        self.data_.append([msg.accel.linear.x,msg.accel.linear.y, msg.accel.angular.z])
        if (msg.header.seq % self.threshold_ is 0): 
           #plt.plot(self.step_, self.data_)
           self.f_ = plt.figure()
           self.ax_ = self.f_.gca()
           #plt.show()
           self.ax_.plot(self.step_,self.data_)
           self.f_.canvas.draw()
           del self.step_[:]
           del self.data_[:]
           self.f_.show()

