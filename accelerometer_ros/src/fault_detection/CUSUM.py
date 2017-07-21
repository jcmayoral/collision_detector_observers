import rospy
from FaultDetection import ChangeDetection
from accelerometer_ros.RealTimePlotter import RealTimePlotter
import matplotlib
matplotlib.use('TkAgg')
import matplotlib.pyplot as plt

class CUSUM(RealTimePlotter):
    def __init__(self, threshold = 1000, pace = 200, seconds=1):
        super().__init__(threshold,pace)
        rospy.init_node("accelerometer_cusum", anonymous=True)
        self.changeDetection = ChangeDetection(seconds)
        plt.show()
        rospy.spin()
        plt.close("all")
