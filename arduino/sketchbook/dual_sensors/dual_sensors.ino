#include <Wire.h>

int ACC_addr= 0x53; 
int MPU_addr=0x68;  

void setup(){

Serial.begin(9600); //this creates the Serial Monitor
setupIMU();
setupACC();
}

void loop(){
  readACC();readIMU();delay(2000);
}

void readIMU(){
  /*
  int16_t AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ;
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x3B);  // starting with register 0x3B (ACCEL_XOUT_H)
  Wire.requestFrom(MPU_addr,14,true);  // request a total of 14 registers
  AcX=Wire.read()<<8|Wire.read();  // 0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)    
  AcY=Wire.read()<<8|Wire.read();  // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
  AcZ=Wire.read()<<8|Wire.read();  // 0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)
  Tmp=Wire.read()<<8|Wire.read();  // 0x41 (TEMP_OUT_H) & 0x42 (TEMP_OUT_L)
  GyX=Wire.read()<<8|Wire.read();  // 0x43 (GYRO_XOUT_H) & 0x44 (GYRO_XOUT_L)
  GyY=Wire.read()<<8|Wire.read();  // 0x45 (GYRO_YOUT_H) & 0x46 (GYRO_YOUT_L)
  GyZ=Wire.read()<<8|Wire.read();  // 0x47 (GYRO_ZOUT_H) & 0x48 (GYRO_ZOUT_L)
   Wire.endTransmission();

  
  Serial.print("AcX = "); Serial.print(AcX);
  Serial.print(" | AcY = "); Serial.print(AcY);
  Serial.print(" | AcZ = "); Serial.print(AcZ);
  Serial.print(" | Tmp = "); Serial.print(Tmp/340.00+36.53);  //equation for temperature in degrees C from datasheet
  Serial.print(" | GyX = "); Serial.print(GyX);
  Serial.print(" | GyY = "); Serial.print(GyY);
  Serial.print(" | GyZ = "); Serial.println(GyZ);
  */
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x3B);
  Wire.endTransmission();

  Wire.beginTransmission(MPU_addr);
  Wire.requestFrom(MPU_addr, 6);

  //while (Wire.available() < 6);

  uint8_t xha = Wire.read();
  uint8_t xla = Wire.read();
        uint8_t yha = Wire.read();
  uint8_t yla = Wire.read();
  uint8_t zha = Wire.read();
  uint8_t zla = Wire.read();
  
    /*#else
  uint8_t xha = Wire.receive();
  uint8_t xla = Wire.receive();
  uint8_t yha = Wire.receive();
  uint8_t yla = Wire.receive();
  uint8_t zha = Wire.receive();
  uint8_t zla = Wire.receive();
    #endif
    }*/

    Serial.println(xha << 8 | xla);
    Serial.println(yha << 8 | yla);
    Serial.println(zha << 8 | zla);

}

void readACC(){
  int16_t AcX,AcY,AcZ;
  Wire.beginTransmission(ACC_addr);
  Wire.write(0x32);  
  Wire.endTransmission(false);

  Wire.requestFrom(ACC_addr,6,true);  // 
 
  AcX=Wire.read()<<8|Wire.read();  //   
  AcY=Wire.read()<<8|Wire.read();  //
  AcZ=Wire.read()<<8|Wire.read();  //
  
  Serial.print("AcX = "); Serial.print(AcX);
  Serial.print(" | AcY = "); Serial.print(AcY);
  Serial.print(" | AcZ = "); Serial.println(AcZ);
  
}


void setupACC(){
  Wire.begin();
  Wire.beginTransmission(ACC_addr);
  Wire.write(0x31);  
  Wire.write(0x01);
  Wire.write(0x2D);  
  Wire.write(0x08);
  Wire.endTransmission();
}

void setupIMU(){
  Wire.begin();
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x6B);  // PWR_MGMT_1 register
  Wire.write(0);     // set to zero (wakes up the MPU-6050)
  Wire.endTransmission();
}


