#include <xc.h> 
#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/examples/i2c1_master_example.h"
// #define I2C_ADDR_HIH6130 0x27
// double humidity;
// uint8_t HUdata[2]; // Define as global

static i2c1_operations_t wr1RegCompleteHandler(void *ptr)
{
    I2C1_SetBuffer(ptr,1);
    I2C1_SetDataCompleteCallback(NULL,NULL);
    return I2C1_CONTINUE;
}
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
}
