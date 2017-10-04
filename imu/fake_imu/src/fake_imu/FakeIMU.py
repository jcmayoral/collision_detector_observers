import rospy
from sensor_msgs.msg import Imu, PointCloud2
from nav_msgs.msg import Odometry
from geometry_msgs.msg import Twist, Vector3, PoseWithCovarianceStamped, Quaternion

class FakeIMU:

    def __init__(self):
        rospy.init_node('fake_imu', anonymous=True)
        rospy.Subscriber("~/base/odometry_controller/odometry",Odometry, self.OdomCB)
        self.imu_Publisher = rospy.Publisher("/imu", Imu, queue_size = 1)
        self.odom_Publisher = rospy.Publisher("/odom", Odometry, queue_size = 1)
        self.freq = 200
        self.orientation = Quaternion()
        self.twist = Twist()
        self.is_shutdown = False
        print "Republisher Node Initialized"

    def OdomCB(self,msg):
        msg.child_frame_id = "base_link"
        msg.header.frame_id = "base_link"
        self.odom_Publisher.publish(msg)
        self.orientation = msg.pose.pose.orientation
        self.twist = msg.twist.twist

    def publishImuMsg(self):
        #This code do not consider covariance
        tmp = Imu()
        tmp.header.frame_id = "base_link"
        tmp.orientation = self.orientation

        tmp.linear_acceleration.x = self.twist.linear.x / self.freq
        tmp.linear_acceleration.y = self.twist.linear.y / self.freq
        tmp.angular_velocity.z = self.twist.angular.z / self.freq
        self.imu_Publisher.publish(tmp)
        self.is_Pose_received = False
        self.is_Twist_received = False

    def shutdown(self):
        self.is_shutdown = True
        print("Node Down")

    def run(self, frequency = 0):

        if frequency is not 0:
            self.freq = frequency

        rospy.on_shutdown(self.shutdown)
        r = rospy.Rate(self.freq)

        while not self.is_shutdown:
            #print "Running"
            self.publishImuMsg()
            r.sleep()
        print ("Node Shutting down")
