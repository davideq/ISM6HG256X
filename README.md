# ISM6HG256X
Arduino library to support the ISM6HG256X.

## API

This sensor uses I2C, SPI, or I3C to communicate.
For I2C it is then required to create a TwoWire interface before accessing to the sensors:  

    TwoWire dev_i2c(I2C_SDA, I2C_SCL);  
    dev_i2c.begin();

For SPI it is then required to create a SPI interface before accessing to the sensors:  

    SPIClass dev_spi(SPI_MOSI, SPI_MISO, SPI_SCK);  
    dev_spi.begin();

An instance can be created and enabled when the I2C bus is used following the procedure below:  

    ISM6HG256XSensor sensor(&dev_i2c);
    sensor.begin();
    sensor.Enable_X();
    sensor.Enable_G();

An instance can be created and enabled when the I3C bus is used with SETDASA:

    ISM6HG256XSensor sensor(&I3C, ISM6HG256X_I3C_ADD_H);
    I3C.begin(I3C_SDA, I3C_SCL, 1000000U);
    I3C.resetDynamicAddresses();
    I3C.assignDynamicAddress(sensor.getStaticAddress(), 0x30);
    sensor.begin(0x30);
    sensor.Enable_X();
    sensor.Enable_G();

An instance can be created and enabled when the SPI bus is used following the procedure below:  

    ISM6HG256XSensor sensor(&dev_spi, CS_PIN);  
    sensor.begin();
    sensor.Enable_X();
    sensor.Enable_G();

The access to the sensor values is done as explained below:  

    ISM6HG256X_Axes_t accel, angrate;
    sensor.Get_X_Axes(accel);
    sensor.Get_G_Axes(&angrate);  

## Examples

* ISM6HG256X_DataLog_Terminal_I2C: This application shows how to get data from ISM6HG256X and print them on terminal over I2C.

* ISM6HG256X_6D_Orientation_I2C: This application shows how to use ISM6HG256X to find out the 6D orientation and display data on a hyperterminal over I2C.

* ISM6HG256X_Double_Tap_Detection_I2C: This application shows how to detect the double tap event using the ISM6HG256X over I2C.

* ISM6HG256X_FIFO_Polling_I2C: This application shows how to get data from FIFO in pooling mode and print them on terminal over I2C.

* ISM6HG256X_FIFO_Interrupt_I2C: This application shows how to get data from FIFO using interrupt and print them on terminal over I2C.

* ISM6HG256X_Free_Fall_Detection_I2C: This application shows how to detect the free fall event using the ISM6HG256X over I2C.

* ISM6HG256X_Pedometer_I2C: This application shows how to use ISM6HG256X to count steps over I2C.

* ISM6HG256X_Single_Tap_Detection_I2C: This application shows how to detect the single tap event using the ISM6HG256X over I2C.

* ISM6HG256X_Tilt_Detection_I2C: This application shows how to detect the tilt event using the ISM6HG256X over I2C.

* ISM6HG256X_Wake_Up_Detection_I2C: This application shows how to detect the wake-up event using the ISM6HG256X over I2C.

* ISM6HG256X_DataLog_Terminal_I3C: This application shows how to get accelerometer and gyroscope data over I3C using SETDASA.

* ISM6HG256X_DataLog_Terminal_I3C_ENTDAA: This application shows how to discover and use ISM6HG256X over I3C.

## Documentation

You can find the source files at  
https://github.com/stm32duino/ISM6HG256X

The ISM6HG256X datasheet is available at  
https://www.st.com/content/st_com/en/products/mems-and-sensors/accelerometers/ISM6HG256X.html
