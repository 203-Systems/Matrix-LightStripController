#include "MatrixSystem.h"

EEPROMClass EEPROM_USER;
EEPROMClass EEPROM_PALETTE;
EEPROMClass EEPROM_SYS;

extern LED LED;
extern MIDI Midi;
extern USBCompositeSerial CompositeSerial;

void setupUSB()
{
  USBComposite.setProductString(DEVICENAME);
  USBComposite.setVendorId(VID);
  USBComposite.setProductId(PID);

  USBComposite.setManufacturerString(MAUNFACTURERNAME);
  USBComposite.setSerialString(SERIALSTRING);

  Midi.registerComponent();
  // CompositeSerial.registerComponent();
  USBComposite.begin();
}

void setupHardware()
{
  LED.init();
  pinMode(sys_led, OUTPUT);
}

void setSystemLED(s8 state)
// STLink(Signal LED) -1 for off 0 for off, 1 for On
// STLink(Dual LED) -1 for off 0 for Red, 1 for Blue/Green
{
  switch (state)
  {
    case -1:
    pinMode(sys_led, INPUT_FLOATING);
    break;

    case 0:
    pinMode(sys_led, OUTPUT);
    digitalWrite(sys_led, LOW);
    break;

    case 1:
    pinMode(sys_led, OUTPUT);
    digitalWrite(sys_led, HIGH);
    break;
  }
}
