#include "ADS131M08.h"
#include "ADS131ESP.h"









ADS131M08 adc;

unsigned long long sampleNum = 0;
unsigned long long currentMicros = 0;
char outputarr[132];

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("ADS131M08 Test");
  adc.begin();

  adc.RESET();

  adc.STANDBY();

  // Disable all ADC and set clocks 250 sps
  adc.writeReg(ADS131_CLOCK,0b1111111100011110); //Clock register (page 55 in datasheet)

  /*CLOCK REG SETTINGS
   * Bits 15-8: ADC Channel enable/disable
   * Bit 7: Crystal disable 
   * Bit 6: External Reference Enable
   * Bit 5: Reserved
   * Bits 4-2: Modulator Oversampling 000 = 128 OSR (32ksps), 111 = 16256 OSR (250sps)
   * Bits 1-0: Power mode selections 11 or 10 = high resolution, 01 = low power, 00 = very low power
   */

  adc.writeReg(ADS131_CFG,0b0000000000000000);

  //DC Block Filter settings:
  //adc.writeReg(ADS131_THRSHLD_LSB,0b0000000000000100);

  //Channel settings
  //adc.writeReg(ADS131_CH0_CFG,0b0000000000000000);

  //Gain settings, 1-128 (increasing by factor of 2)
  
  adc.setGain(8);

  uint16_t stat = adc.NULL_STATUS();
  Serial.print("Status: ");
  Serial.println(stat, HEX);

  uint16_t Id = adc.readReg(ADS131_ID);
  Serial.print("Id: ");
  Serial.println(Id, HEX); 

  uint16_t Mode = adc.readReg(ADS131_MODE);
  Serial.print("Mode: ");
  Serial.println(Mode, HEX);

   
  uint16_t clkreg = adc.readReg(ADS131_CLOCK);
  Serial.print("CLOCK: ");
  Serial.println(clkreg,HEX);
  

  
  uint16_t gainreg1 = adc.readReg(ADS131_GAIN1);
  Serial.print("GAIN1: ");
  Serial.println(gainreg1, HEX);

  uint16_t gainreg2 = adc.readReg(ADS131_GAIN2);
  Serial.print("GAIN2: ");
  Serial.println(gainreg2, HEX);
  
  //adc.globalChop(true,2);
  
  
  

  adc.WAKEUP();

  currentMicros = esp_timer_get_time();

}


void loop() {
  int32_t channelData[8];

  if (adc.getData(channelData)) {
    currentMicros = esp_timer_get_time();
    sampleNum++;
    sprintf(outputarr, "%d,%d,%d,%d,%d,%d,%d,%d\n", 
              channelData[0], 
              channelData[1], 
              channelData[2],
              channelData[3],
              channelData[4],
              channelData[5],
              channelData[6],
              channelData[7]
              );
              
    Serial.print(outputarr);

    
  }
  
}
