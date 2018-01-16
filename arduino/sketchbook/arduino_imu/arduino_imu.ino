#include <ros.h>
#include <Wire.h>
#include <std_msgs/String.h>
#include <geometry_msgs/AccelStamped.h>
#include <sensor_msgs/Imu.h>

const int DEVICE_ADDRESS = (0x68);  

byte _buff[14];

//Direcciones de los registros del MPU6050
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
  Serial.begin(9600);
  //Wire.begin();
  //writeTo(DEVICE_ADDRESS, DATA_FORMAT, 0x01); //Poner ADXL345 en +- 4G
  //writeTo(DEVICE_ADDRESS, POWER_CTL, 0x08);  //Poner el ADXL345 
  //nh.initNode();
  //nh.advertise(imu_pub);
  writeTo(DEVICE_ADDRESS, 0x6B, 0);  // PWR_MGMT_1 register
  nh.initNode();
  nh.advertise(imu_pub);
}

void loop()
{
  readImu(); //Leer aceleracion x, y, z
  nh.spinOnce();
}

void readImu() {
  //Leer los datos
  uint8_t numBytesToRead = 14;
  readFrom(DEVICE_ADDRESS, DATAX0, numBytesToRead, _buff);

  //Leer los valores del registro y convertir a int (Cada eje tiene 10 bits, en 2 Bytes LSB)
  int ax = (((int)_buff[1]) << 8) | _buff[0];   // 3B
  int ay = (((int)_buff[3]) << 8) | _buff[2];   // 3D
  int az = (((int)_buff[5]) << 8) | _buff[4];
  int t = (((int)_buff[7]) << 8) | _buff[6];
  int gx = (((int)_buff[9]) << 8) | _buff[8];   
  int gy = (((int)_buff[11]) << 8) | _buff[10];
  int gz = (((int)_buff[13]) << 8) | _buff[12];
  output_msg.header.frame_id = frame_;
  output_msg.header.stamp = nh.now();
  output_msg.linear_acceleration.x = ax;
  output_msg.linear_acceleration.y = ay;
  output_msg.linear_acceleration.z = az;  
  imu_pub.publish(&output_msg);
  Serial.print("AcX = "); Serial.print(ax);
  Serial.print(" | AcY = "); Serial.print(ay);
  Serial.print(" | AcZ = "); Serial.print(az);
  Serial.print(" | Tmp = "); Serial.print(t/340.00+36.53);  //equation for temperature in degrees C from datasheet
  Serial.print(" | GyX = "); Serial.print(gx);
  Serial.print(" | GyY = "); Serial.print(gy);
  Serial.print(" | GyZ = "); Serial.println(gz);

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

