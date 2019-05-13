#ifndef DEVICE_SELECTOR_H
#define DEVICE_SELECTOR_H

#include "../Parameter/MatrixParameter.h"


extern u8 led_pin;
extern u8 sys_led_pin;

extern u32 led_color_correction;

extern bool support_wrgb;

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
