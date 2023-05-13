#ifndef ADS131M08_H
#define ADS131M08_H
//ADS131M08.cpp LGPL 
//Adapted for the 8 channel device from https://github.com/icl-rocketry/ADS131M04-Lib (LGPL)


/* Definitions of all the addresses of the registers of the ADS131M04
   Chip. For the content of the registers, please refer to the datasheet:

   https://www.ti.com/lit/gpn/ads131m04

   Written by Imperial College London Rocketry
   Electronics subteam
*/

#include <Arduino.h>
#include <SPI.h>

#define ADS131_CMD_NULL       0x0000
#define ADS131_CMD_RESET      0x0011
#define ADS131_CMD_STANDBY    0x0022
#define ADS131_CMD_WAKEUP     0x0033
#define ADS131_CMD_LOCK       0x0555
#define ADS131_CMD_UNLOCK     0x0655
#define ADS131_CMD_RREG       0xa000
#define ADS131_CMD_WREG       0x6000

#define ADS131_ID 0x00
#define ADS131_STATUS 0x01
#define ADS131_MODE 0x02
#define ADS131_CLOCK 0x03
#define ADS131_GAIN1 0x04
#define ADS131_GAIN2 0x05
#define ADS131_CFG 0x06
#define ADS131_THRSHLD_MSB 0x07
#define ADS131_THRSHLD_LSB 0x08

#define ADS131_CH0_CFG 0x09
#define ADS131_CH0_OCAL_MSB 0x0A
#define ADS131_CH0_OCAL_LSB 0x0B
#define ADS131_CH0_GCAL_MSB 0x0C
#define ADS131_CH0_GCAL_LSB 0x0D
#define ADS131_CH1_CFG 0x0E
#define ADS131_CH1_OCAL_MSB 0x0F
#define ADS131_CH1_OCAL_LSB 0x10
#define ADS131_CH1_GCAL_MSB 0x11
#define ADS131_CH1_GCAL_LSB 0x12
#define ADS131_CH2_CFG 0x13
#define ADS131_CH2_OCAL_MSB 0x14
#define ADS131_CH2_OCAL_LSB 0x15
#define ADS131_CH2_GCAL_MSB 0x16
#define ADS131_CH2_GCAL_LSB 0x17
#define ADS131_CH3_CFG 0x18
#define ADS131_CH3_OCAL_MSB 0x19
#define ADS131_CH3_OCAL_LSB 0x1A
#define ADS131_CH3_GCAL_MSB 0x1B
#define ADS131_CH3_GCAL_LSB 0x1C
#define ADS131_CH4_CFG 0x1D
#define ADS131_CH4_OCAL_MSB 0x1E
#define ADS131_CH4_OCAL_LSB 0x1F
#define ADS131_CH4_GCAL_MSB 0x20
#define ADS131_CH4_GCAL_LSB 0x21
#define ADS131_CH5_CFG 0x22
#define ADS131_CH5_OCAL_MSB 0x23
#define ADS131_CH5_OCAL_LSB 0x24
#define ADS131_CH5_GCAL_MSB 0x25
#define ADS131_CH5_GCAL_LSB 0x26
#define ADS131_CH6_CFG 0x27
#define ADS131_CH6_OCAL_MSB 0x28
#define ADS131_CH6_OCAL_LSB 0x29
#define ADS131_CH6_GCAL_MSB 0x2A
#define ADS131_CH6_GCAL_LSB 0x2B
#define ADS131_CH7_CFG 0x2C
#define ADS131_CH7_OCAL_MSB 0x2D
#define ADS131_CH7_OCAL_LSB 0x2E
#define ADS131_CH7_GCAL_MSB 0x2F
#define ADS131_CH7_GCAL_LSB 0x30


#define ADS131_REGMAP_CRC 0x3E
#define ADS131_RESERVED 0x3F


class ADS131M08 {
    public:

    
    bool firstRead = true;
    int nFrameWords = 10;
    // Dummy word frame to write ADC during ADC data reads
    ADS131M08(void);
    void begin(void);
    void hw_reset();

    // System Commands
    uint16_t NULL_STATUS(void);
    bool RESET(void);
    void STANDBY(void);
    void WAKEUP(void);
    void LOCK();
    void UNLOCK(void);

    // Register Read/Write Commands
    bool writeReg(uint16_t reg, uint16_t data);
    uint16_t readReg(uint16_t reg);

    //Data Read functions
    bool getData(int32_t *buffer);

    // Functions for setup and data retrieval
    bool globalChop(bool enabled, uint8_t log2delay);
    bool setGain(int gain);
    uint32_t spiTransferWord(uint16_t inputData = 0x0000);
    void spiCommFrame(uint32_t * outPtr, uint16_t command = 0x0000, uint16_t data = 0x0000);
    int32_t twoCompDeco(uint32_t data);

};

#endif
