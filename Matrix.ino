/*
Project Matrix - LightStrip Controller
Copyright © 203 Industries 2017–2019. All rights reserved.

TODO
EEPROM load KeyMap
EEPROM sys stuff
microsecond timer
Play Animation
Play Midi
Play Text
NexusRevamped while USB unreconized

*/
#include <Arduino.h>
#include <USBMIDI.h>
#include <USBComposite.h>
#include <FastLED.h>
#include "src/Parameter/MatrixVariable.h"
#include "src/Parameter/MatrixParameter.h"
#include "src/Core/MatrixSystem.h"
//#include "../Serials.h"
#include "src/Core/MatrixSystem.h"
#include "src/HAL/LED.h"
#include "src/HAL/Timer.h"
#include "src/Protocol/MIDI.h"

//UIelement uielement;
MIDI Midi;
LED LED;
Timer mainTimer;

void setup()
{
  digitalWrite(led_pin,LOW);
  loadDeviceConfig();
  //setupEEPROM();
  //variableLoad();
  setupHardware();
  //specialBoot();
  setupUSB();

  #ifdef DEBUG
  CompositeSerial.println("Setup Complete");
  #endif

  mainTimer.recordCurrent();
  while(!USBComposite.isReady())
  {
    if (mainTimer.isLonger(10000))
    {
      LED.setHEX(0,0xff0000);
      LED.update();
    }
  }
  LED.fill(0x000000);
  LED.update();

  #ifdef DEBUG
  CompositeSerial.println("Enter Main Program");
  #endif
}

void loop()
{
  Midi.poll();

  if (mainTimer.tick(16))
  {
    Midi.offScan();
    LED.update();
  }
}
