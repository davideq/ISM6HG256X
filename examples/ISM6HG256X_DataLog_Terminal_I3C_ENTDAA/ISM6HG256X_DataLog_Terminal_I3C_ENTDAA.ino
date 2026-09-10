/*
   @file    ISM6HG256X_DataLog_Terminal_I3C_ENTDAA.ino
   @author  STMicroelectronics
   @brief   Example to use the ISM6HG256X sensor with I3C dynamic address assignment
 *******************************************************************************
   Copyright (c) 2026, STMicroelectronics
   All rights reserved.
*******************************************************************************
*/
#include <ISM6HG256XSensor.h>

ISM6HG256XSensor sensor(&I3C);

void setup()
{
  Serial.begin(115200);
  while (!Serial) {}

  if (!I3C.begin(I3C_SDA, I3C_SCL, 1000000U)) {
    while (1) {}
  }
  if (!I3C.resetDynamicAddresses()) {
    while (1) {}
  }

  I3CDiscoveredDevice devices[8] = {};
  size_t found = 0;
  if (I3C.discover(devices, 8, &found)) {
    while (1) {}
  }

  for (size_t index = 0; index < found; ++index) {
    if (sensor.begin(devices[index].dynAddr) == ISM6HG256X_OK) {
      break;
    }
  }
  if (sensor.getDynAddress() == 0U) {
    while (1) {}
  }
  if (!I3C.setClock(12500000)) {
    while (1) {}
  }
  if (sensor.Enable_X() != ISM6HG256X_OK || sensor.Enable_G() != ISM6HG256X_OK) {
    while (1) {}
  }
}

void loop()
{
  ISM6HG256X_Axes_t accel;
  ISM6HG256X_Axes_t angrate;

  if (sensor.Get_X_Axes(&accel) == ISM6HG256X_OK && sensor.Get_G_Axes(&angrate) == ISM6HG256X_OK) {
    Serial.print("Accel-X[mg]:");
    Serial.print(accel.x);
    Serial.print(",Accel-Y[mg]:");
    Serial.print(accel.y);
    Serial.print(",Accel-Z[mg]:");
    Serial.println(accel.z);
    Serial.print("AngRate-X[mdps]:");
    Serial.print(angrate.x);
    Serial.print(",AngRate-Y[mdps]:");
    Serial.print(angrate.y);
    Serial.print(",AngRate-Z[mdps]:");
    Serial.println(angrate.z);
  }
  delay(500);
}
