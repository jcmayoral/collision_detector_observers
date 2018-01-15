// MPU-6050 Short Example Sketch
// By Arduino User JohnChi
// August 17, 2014
// Public Domain
// Modified by Jose Mayoral for ROS


#include<Wire.h>
// ROS dependencies
#include <ros.h>
#include <std_msgs/String.h>
#include <sensor_msgs/Imu.h>

//ROS objects
ros::NodeHandle nh;
sensor_msgs::Imu output_msg;
ros::Publisher imu_pub("imu", &output_msg);
char frame_[]= "imu_frame";

const int MPU_addr=0x68;  // I2C address of the MPU-6050
int16_t AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ;

void setup(){
  Wire.begin();
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x6B);  // PWR_MGMT_1 register
  Wire.write(0);     // set to zero (wakes up the MPU-6050)
  Wire.endTransmission(true);
  Serial.begin(57000);// defaullt 9600
  nh.initNode();
  nh.advertise(imu_pub);
}
void loop(){
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x3B);  // starting with register 0x3B (ACCEL_XOUT_H)
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_addr,14,true);  // request a total of 14 registers
  AcX=Wire.read()<<8|Wire.read();  // 0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)    
  AcY=Wire.read()<<8|Wire.read();  // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
  AcZ=Wire.read()<<8|Wire.read();  // 0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)
  Tmp=Wire.read()<<8|Wire.read();  // 0x41 (TEMP_OUT_H) & 0x42 (TEMP_OUT_L)
  GyX=Wire.read()<<8|Wire.read();  // 0x43 (GYRO_XOUT_H) & 0x44 (GYRO_XOUT_L)
  GyY=Wire.read()<<8|Wire.read();  // 0x45 (GYRO_YOUT_H) & 0x46 (GYRO_YOUT_L)
  GyZ=Wire.read()<<8|Wire.read();  // 0x47 (GYRO_ZOUT_H) & 0x48 (GYRO_ZOUT_L)
  
  // TO ROS TOPIC
  //output_msg.header.stamp = nh.now();
  //output_msg.header.frame_id = frame_;
  imu_pub.publish(&output_msg);
  Serial.print("AcX = "); Serial.print(AcX);
  Serial.print(" | AcY = "); Serial.print(AcY);
  Serial.print(" | AcZ = "); Serial.print(AcZ);
  Serial.print(" | Tmp = "); Serial.print(Tmp/340.00+36.53);  //equation for temperature in degrees C from datasheet
  Serial.print(" | GyX = "); Serial.print(GyX);
  Serial.print(" | GyY = "); Serial.print(GyY);
  Serial.print(" | GyZ = "); Serial.println(GyZ);
  //delay(333);
  nh.spinOnce();
}


/*
 * Arduino ROS interface accelerometer 
 * author: Jose Mayoral
 * Based on:
 * https://www.luisllamas.es/arduino-acelerometro-adxl345/
 * for ROS Arduino interface
 * and 
 * http://wiki.ros.org/rosserial_arduino/Tutorials
 * as Serial Device Inteface Tutorial
 */

/*
#include <ros.h>
#include <Wire.h>
#include <std_msgs/String.h>
#include <geometry_msgs/AccelStamped.h>
#include <sensor_msgs/Imu.h>

const int DEVICE_ADDRESS = (0x68);  

byte _buff[6];

//Direcciones de los registros del ADXL345
char POWER_CTL = 0x2D;
char DATA_FORMAT = 0x31;
char DATAX0 = 0x3B;	//X-Axis Data 0
char DATAX1 = 0x3C;	//X-Axis Data 1
char DATAY0 = 0x3D;	//Y-Axis Data 0
char DATAY1 = 0x3E;	//Y-Axis Data 1
char DATAZ0 = 0x3F;	//Z-Axis Data 0
char DATAZ1 = 0x40;	//Z-Axis Data 1

ros::NodeHandle nh;
sensor_msgs::Imu output_msg;
ros::Publisher imu_pub("imu", &output_msg);
char frame_[]= "imu_frame";

void setup()
{
  Serial.begin(57000);
  Wire.begin();
  writeTo(DEVICE_ADDRESS, DATA_FORMAT, 0x01); //Poner ADXL345 en +- 4G
  writeTo(DEVICE_ADDRESS, POWER_CTL, 0x08);  //Poner el ADXL345 
  nh.initNode();
  nh.advertise(acc_pub);
}

void loop()
{
  readImu(); //Leer aceleracion x, y, z
  nh.spinOnce();
}

void readAccel() {
  //Leer los datos
  uint8_t numBytesToRead = 6;
  readFrom(DEVICE_ADDRESS, DATAX0, numBytesToRead, _buff);

  //Leer los valores del registro y convertir a int (Cada eje tiene 10 bits, en 2 Bytes LSB)
  int x = (((int)_buff[1]) << 8) | _buff[0];   
  int y = (((int)_buff[3]) << 8) | _buff[2];
  int z = (((int)_buff[5]) << 8) | _buff[4];
  acc_msg.header.frame_id = frame_;
  acc_msg.header.stamp = nh.now();
  acc_msg.accel.linear.x = x;
  acc_msg.accel.linear.y = y;
  acc_msg.accel.angular.z = z;
  acc_pub.publish( &acc_msg );
  Serial.print("x: ");
  Serial.print( x );
  Serial.print(" y: ");
  Serial.print( y );
  Serial.print(" z: ");
  Serial.println( z );
}


//Funcion auxiliar de escritura
void writeTo(int device, byte address, byte val) {
  Wire.beginTransmission(device);
  Wire.write(address);
  Wire.write(val);
  Wire.endTransmission(); 
}

//Funcion auxiliar de lectura
void readFrom(int device, byte address, int num, byte _buff[]) {
  Wire.beginTransmission(device);
  Wire.write(address);
  Wire.endTransmission();

  Wire.beginTransmission(device);
  Wire.requestFrom(device, num);

  int i = 0;
  while(Wire.available())
  { 
    _buff[i] = Wire.read();
    i++;
  }
  Wire.endTransmission();
}

*/
