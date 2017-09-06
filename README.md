# RASPBERRY PI and Arduino ROS REPOSITORIES #

Arduino ROS Installation Tutorial Followed: </br>

   http://wiki.ros.org/rosserial_arduino/Tutorials

# accelerometer_ros #

This ROS package gives multiple functionalities using the Fault_Detector library provided at https://github.com/jcmayoral/myRaspberryPI through the use of a accelerometer. The scripts contained are:

1. accelerometer_node: suitable for publishing raw measurements from an accelerometer connected in a RaspBerryPI using the Adafruit_Python_ADXL345 driver.
1. accelerometer_plot: use the RealTimePloting interface to plot raw data comming subscribing to a topic.
1. accelerometer_gauss: similar to accelerometer_plot but plot gauss distribution of a window of raw data of the accelerometer.
1. accelerometer_cusum: an extension of teh accelerometer_plot implementing the CUSUM algorithm provided in the Fault_Detector library.
1. accelerometer_for_fusion: accelerometer_cusum modification without RealTimePlot compatible with the move_base_fault_tolerant.

