#include "../DeviceSelector.h"

void loadConfigSTLINKV2M1()
{

  //LED
  nums_led_channel_available = 4;
  led_pins[0] = PB6; //RST
  led_pins[1] = PB11; //SWIM
  led_pins[2] = PA5; //SWCLK
  led_pins[3] = PB14; //SWDIO
  sys_led = PA9;

  led_color_correction = 0xFFFFFF;

  brightness_button = 0;

  flash_button = 0;

  //EEPROM
  eeprom_enable = false;
  eeprom_user_adds_0 = 0;
  eeprom_user_adds_1 = 0;
  eeprom_palette_adds_0 = 0;
  eeprom_palette_adds_1 = 0;
  eeprom_sys_adds_0 = 0;
  eeprom_sys_adds_1 = 0;
  eeprom_pagesize = 0x400;
}
