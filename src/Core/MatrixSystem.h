#ifndef SYSTEM_H
#define SYSTEM_H

#include <Arduino.h>
#include <EEPROM.h>
#include <libmaple/bkp.h>
#include <libmaple/nvic.h>
#include <USBComposite.h>
#include <USBMIDI.h>
#include <FastLED.h>
#include "../Parameter/MatrixVariable.h"
#include "../Parameter/MatrixParameter.h"
#include "../Parameter/DeviceSelector.h"
#include "../HAL/LED.h"
#include "../Protocol/MIDI.h"

void bootDevice();

void setupUSB();
void setupHardware();
void setSystemLED(s8 state);



#endif
