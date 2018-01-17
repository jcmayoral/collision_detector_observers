import rospy
from CollisionSensorTemplate import SensorFusion
from geometry_msgs.msg import AccelStamped
from fusion_msgs.msg import sensorFusionMsg
import numpy as np

#Dynamic Reconfigure
from dynamic_reconfigure.server import Server
from accelerometer_ros.cfg import accelerometerConfig

class AccFusionTemplate(SensorFusion):
    def __init__(self):
        SensorFusion.__init__(self,
                              number_elements = 3,
                              cusum_window_size = 10,
                              frame_id = "imu_frame",
                              sensor_id = "imu",
                              threshold = 60,
                              node = "acc_collision",
                              sensor_type = AccelStamped,
                              topic_name = "accel",
                              sensor_number = 0,
                              config_type = accelerometerConfig)
