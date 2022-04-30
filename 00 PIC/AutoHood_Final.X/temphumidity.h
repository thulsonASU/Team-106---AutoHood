/*
 * Created by: Aaron Clatone
 * Integrated by: Tyler Hulson
 * Date Updated: 4/26/2022
 * Date Created: 4/14/2022
 */

#include <xc.h> 
#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/examples/i2c1_master_example.h"
float humidity,  huData0, huData1; // set humidity as a global double
uint8_t HUdata[2]; // Define as global

/*
 * \Brief: I wish I could tell you what these handlers did
 */
static i2c1_operations_t wr1RegCompleteHandler(void *ptr)
{
    I2C1_SetBuffer(ptr,1);
    I2C1_SetDataCompleteCallback(NULL,NULL);
    return I2C1_CONTINUE;
}
/*
 * \Brief: I wish I could tell you what these handlers did
 */
static i2c1_operations_t rd1RegCompleteHandler(void *ptr)
{
    I2C1_SetBuffer(ptr,1);
    I2C1_SetDataCompleteCallback(NULL,NULL);
    return I2C1_RESTART_READ;
}

/**
 * \brief Wake up the sensor and perform a measurement. Store the value in 0x00
 * \This function must be called before the data fetch (every time).
 */
void I2C1_measReq(i2c1_address_t address) {
    uint16_t returnValue = 0x00; // returnValue is little endian

    while(!I2C1_Open(address)); // sit here until we get the bus..
    I2C1_MasterWrite();
    I2C1_SetDataCompleteCallback(wr1RegCompleteHandler,&returnValue); //ack
    while(I2C1_BUSY == I2C1_Close()); // sit here until finished.
}

/**
 * \brief Fetch the data that was written during the measurement request command
 * \This function must be called after the measurement request (every time).
 */
void I2C1_dataFetch(i2c1_address_t address, uint8_t *data, size_t len) {
    uint16_t returnValue = 0x00; // returnValue is little endian
    
    while(!I2C1_Open(address)); // sit here until we get the bus..
    I2C1_SetBuffer(data,len);
    data[0] = I2C1_MasterRead();
    I2C1_SetDataCompleteCallback(rd1RegCompleteHandler,&returnValue);   // ack
    data[1] = I2C1_MasterRead();
    //I2C1_MasterSendNack();
    while(I2C1_BUSY == I2C1_Close()); // sit here until finished.
    
    huData0 = (float) HUdata[0];
    huData1 = (float) HUdata[1];
    //humidity = ((((huData0 & 0x3F) * 256) + huData1) * 100) / 16383; // Calculate Humidity            
}
