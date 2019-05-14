#ifndef DEVICE_SELECTOR_H
#define DEVICE_SELECTOR_H

#include "../Parameter/MatrixParameter.h"

extern u8 nums_led_channel_available;
extern u8 led_pins[NUM_LED_STRIP];
extern u8 sys_led;

extern u32 led_color_correction;

extern u8 brightness_button;
extern u8 flash_button;

//EEPROM
extern bool eeprom_enable;
extern u32 eeprom_user_adds_0;
extern u32 eeprom_user_adds_1;
extern u32 eeprom_palette_adds_0;
extern u32 eeprom_palette_adds_1;
extern u32 eeprom_sys_adds_0;
extern u32 eeprom_sys_adds_1;
extern u32 eeprom_pagesize;

void loadDeviceConfig();
void loadConfigSTLINKV2M1();

#endif
