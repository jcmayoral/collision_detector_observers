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
        self.step_.append(msg.seq)
        self.append([msg.accel.linear.x,msg.accel.linear.y, msg.accel.angular.z])
        if (msg.seq % self.threshold is 0): 
           plt.plot(self.step_, self.data_[:,0])
           plt.plot(self.step_, self.data_[:,1])
           plt.plot(self.step_, self.data_[:,2])
           plt.show()
           del self.step_[:]
           del self.data_[:]

