import Adafruit_ADXL345
import rospy
from geometry_msgs.msg import AccelStamped

class Republisher:

    def __init__(self):
        rospy.init_node('acceleometer_ros', anonymous=True)
        self.imu_Publisher = rospy.Publisher("/accel", AccelStamped, queue_size = 1)
        self.accel = Adafruit_ADXL345.ADXL345()
        self.seq = 0
        print "Publisher Node Initialized"

    def run(self, frequency = 0):
        x, y, z = self.accel.read()
        msg = AccelStamped()
        msg.header.stamp = rospy.Time.now()
        msg.header.frame_id = "accel_frame"
        msg.seq = self.seq
        seq = seq + 1
        rospy.spin()
