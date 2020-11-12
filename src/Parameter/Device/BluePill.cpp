#include "../DeviceSelector.h"

void loadConfigBluePill()
{

  //LED
  nums_led_channel_available = 4;
  led_pins[0] = PA1;
  led_pins[1] = PA2;
  led_pins[2] = PA3;
  led_pins[3] = PA4;
  sys_led = PC13;

  led_color_correction = 0xFFFFFF;

  brightness_button = PA0;

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
