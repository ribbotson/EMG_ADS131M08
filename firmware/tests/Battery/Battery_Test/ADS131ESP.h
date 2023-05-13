/*
 OBCIESP_HW.h
 Header File with hardware definitions for OpenBCI_ESP Base board
 License: GNU General Public License V3
       
 (C) Copyright 2022 Richard Ibbotson
 */

#ifndef __ADS131ESP_H__
#define __ADS131ESP_H__


#define DEVKIT_C            // Original Board which uses DevKIT C
//#define WROOM               //   // New Board with WROOM and LiPo

#define SERIAL_0_PORT       BTSERIAL // The primary serial Port will use the Bluetooth serial

#define SERIAL_1_PORT       ESP_SERIAL_0  // The serial debug and test port will be over the USB port
#define SERIAL_TX_PIN       3
#define SERIAL_RX_PIN       1

#if defined(DEVKIT_C) 
#define LED_1_PIN           19
#define LED_2_PIN           18
#define BUTTON_1_PIN        26
#define BUTTON_2_PIN        27
#define BATT_PORT           ADC1_CH0  // Measure 5V Rail
#define BATT_PIN            36    // via 220k/120k divider
#define BATT_MAX            (3.3f * (220.0f + 120.0f)/120.0f)

#elif defined(WROOM) 
#define LED_1_PIN           4   // WiFi LED
#define LED_2_PIN           16  // Bluetooth LED
#define STATUS_PIN          19  // Status LED
#define BUTTON_1_PIN        26
#define BUTTON_2_PIN        27
#define BATT_PORT           ADC1_CH6  // Measure Battery Voltage
#define BATT_PIN            34    // via 220k/120k divider
#define BATT_MAX            (3.3f * (220.0f + 120.0f)/120.0f)

#else 
#error "Unknown Board Type"
#endif

#define ACCEL_PORT          I2C
#define ACCEL_SDA_PIN       21
#define ACCEL_SCL_PIN       22
#define ACCEL_INT_PIN       27
#define ACCEL_I2C_ADDRESS   0x19


#define ADS131_PORT        HSPI
#define ADS131_MOSI_PIN    13
#define ADS131_MISO_PIN    12
#define ADS131_SCK_PIN     14
#define ADS131_SSEL_PIN    15
#define ADS131_RESET_PIN   17
#define ADS131_DRDY_PIN    25




#endif // __ADS131ESP_H__
