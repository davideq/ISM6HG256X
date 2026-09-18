/*
   @file    ISM6HG256X_DataLog_Terminal_I2C.ino
   @author  STMicroelectornics
   @brief   Example to use the ISM6HG256X inertial measurement sensor.
 *******************************************************************************
   Copyright (c) 2025, STMicroelectronics
   All rights reserved.
   This software component is licensed by ST under BSD 3-Clause license,
   the "License"; You may not use this file except in compliance with the
   License. You may obtain a copy of the License at:
                          opensource.org/licenses/BSD-3-Clause
 *******************************************************************************
*/

#include <ISM6HG256XSensor.h>

ISM6HG256XSensor sensor(&Wire);
ISM6HG256X_Axes_t accel, angrate;

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(115200);
  Wire.begin();
  sensor.begin();
  sensor.Enable_X();
  sensor.Enable_G();
}

void loop()
{
  sensor.Get_X_Axes(&accel);
  sensor.Get_G_Axes(&angrate);

  Serial.print("Accel-X[mg]:");
  Serial.print(accel.x);
  Serial.print(",Accel-Y[mg]:");
  Serial.print(accel.y);
  Serial.print(",Accel-Z[mg]:");
  Serial.print(accel.z);

  Serial.print(",AngRate-X[mdps]:");
  Serial.print(angrate.x);
  Serial.print(",AngRate-Y[mdps]:");
  Serial.print(angrate.y);
  Serial.print(",AngRate-Z[mdps]:");
  Serial.println(angrate.z);

  blink(LED_BUILTIN);
}

inline void blink(int pin)
{
  digitalWrite(pin, HIGH);
  delay(25);
  digitalWrite(pin, LOW);
  delay(975);
}
