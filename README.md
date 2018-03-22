# RASPBERRY PI and Arduino ROS REPOSITORIES #

Arduino ROS Installation Tutorial Followed:

   http://wiki.ros.org/rosserial_arduino/Tutorials

# accelerometer #

## accelerometer_ros ##

This ROS package gives multiple functionalities using the Fault_Detector library provided at https://github.com/jcmayoral/myRaspberryPI through the use of a accelerometer. The scripts contained are:

1. accelerometer_node: suitable for publishing raw measurements from an accelerometer connected in a RaspBerryPI using the Adafruit_Python_ADXL345 driver.
1. accelerometer_plot: use the RealTimePloting interface to plot raw data coming subscribing to a topic.
1. accelerometer_gauss: similar to accelerometer_plot but plot gauss distribution of a window of raw data of the accelerometer.
1. accelerometer_cusum: an extension of the accelerometer_plot implementing the CUSUM algorithm provided in the Fault_Detector library.
1. accelerometer_for_fusion: accelerometer_cusum modification without RealTimePlot compatible with the move_base_fault_tolerant.
1. acc_template: accelerometer_for_fusion using the CollisionSensorTemplates of repository myRaspberryPI. Test is required.

# arduino #

Arduino programs are available for set up an arduino for an acceerometer or an IMU.

1. arduino_accelerometer: Interface for ROS compatible accelerometer.
1. arduino_imu: ROS Interface for IMU through an arduino.
1. arduino_imu_2: A second interface for ROS in order to use it within arduino (Not working).
1. dual_sensors: Since accelerometer and imu use i2C protocol both can be running together. (Not working, potentially pull up resistors are needed).

After uploading the desired code to the arduino the following command must be run in a terminal.

rosrun rosserial_python serial_node.py /dev/ttyACM#

Where # stands for the ID of the arduino provided by the OS.

#Collision Observers#

Contains a set of collision observers which are modified to detect collision on mobile robots. All are based on a CUSUM (Change Detection Algorithm). The package include observers for accelerometer, localization variance, imu, Kalman Filter, LiDar, Microphones and odometry speeds. Amcl and Odometry have proved not to be reliable, but are integrated for future work and potential modifications.
