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

#include <ros.h>
#include <Wire.h>
#include <std_msgs/String.h>
#include <geometry_msgs/AccelStamped.h>

const int DEVICE_ADDRESS = (0x53);  

byte _buff[6];

//Direcciones de los registros del ADXL345
char POWER_CTL = 0x2D;
char DATA_FORMAT = 0x31;
char DATAX0 = 0x32;	//X-Axis Data 0
char DATAX1 = 0x33;	//X-Axis Data 1
char DATAY0 = 0x34;	//Y-Axis Data 0
char DATAY1 = 0x35;	//Y-Axis Data 1
char DATAZ0 = 0x36;	//Z-Axis Data 0
char DATAZ1 = 0x37;	//Z-Axis Data 1

ros::NodeHandle nh;
geometry_msgs::AccelStamped acc_msg;
ros::Publisher acc_pub("accel", &acc_msg);
char frame_[]= "accel_frame";

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
  readAccel(); //Leer aceleracion x, y, z
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


