/*!
 * @file getSixaxis.ino
 * @brief 用来收集传感器三轴加速度值，并计算Roll及Pitch角度信息
 * @copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @license     The MIT License (MIT)
 * @author      PengKaixing(kaixing.peng@dfrobot.com)
 * @version  V2.0.0
 * @date  2022-02-22
 * @url https://github.com/DFRobot/DFRobot_ADXL345
 */

#include "DFRobot_ADXL345.h"

#define cs_pin 10

DFRobot_ADXL345_I2C ADXL345(&Wire,0x53);
/**
 * 注意在使用leonardo作为主控的时候，需要连接ICSP引脚
 */
// DFRobot_ADXL345_SPI ADXL345(&SPI, cs_pin);

int accval[3];

void setup() 
{
  Serial.begin(9600);
  ADXL345.begin();
  ADXL345.powerOn();
}

void loop() 
{
  ADXL345.readAccel(accval);
  Serial.println("Triaxial acceleration value is :");
  Serial.print("x:");Serial.print(accval[0]);
  Serial.print(" y:");Serial.print(accval[1]);
  Serial.print(" z:");Serial.println(accval[2]);
  ADXL345.RPCalculate(accval);
  Serial.print("Roll:"); Serial.println( ADXL345.RP.roll );
  Serial.print("Pitch:"); Serial.println( ADXL345.RP.pitch );
  delay(500);
}
