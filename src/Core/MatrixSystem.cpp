#include "MatrixSystem.h"

EEPROMClass EEPROM_USER;
EEPROMClass EEPROM_PALETTE;
EEPROMClass EEPROM_SYS;

extern LED LED;
extern MIDI Midi;

void setupUSB()
{
  USBComposite.setProductString(DEVICENAME);
  USBComposite.setVendorId(VID);
  USBComposite.setProductId(PID);

  USBComposite.setManufacturerString(MAUNFACTURERNAME);
  //USBComposite.setProductString(DEVICENAME);
  USBComposite.setSerialString(SERIALSTRING);

  Midi.registerComponent();
  CompositeSerial.registerComponent();
  USBComposite.begin();

}

void setupHardware()
{
  LED.init();
}
