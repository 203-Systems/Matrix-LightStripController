/*
Project Matrix - LightStrip Controller
Copyright © 203 Industries 2017–2020. All rights reserved.
*/

#include <Arduino.h>
#include <USBMIDI.h>
#include <USBComposite.h>
#include <FastLED.h>
#include "src/Parameter/MatrixVariable.h"
#include "src/Parameter/MatrixParameter.h"
#include "src/Core/MatrixSystem.h"
#include "src/HAL/LED.h"
#include "src/HAL/Timer.h"
#include "src/Protocol/MIDI.h"

MIDI Midi;
LED LED;
Timer mainTimer;
// USBCompositeSerial CompositeSerial;

bool LEDstate = false;

void setup()
{
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
    if (mainTimer.tick(200))
    {
      LEDstate = !LEDstate;
      setSystemLED(LEDstate);
    }
  }

  setSystemLED(1);

  LED.rainbow();

  #ifdef DEBUG
  CompositeSerial.println("Enter Main Program");
  #endif
}


void loop()
{
  Midi.poll();

  if (mainTimer.tick(16))
  {
    if(stfu)
    Midi.offScan();
    LED.update();
  }
}
