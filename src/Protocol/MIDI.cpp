#include "MIDI.h"

#ifdef DEBUG
#include <USBComposite.h>
#endif

extern LED LED;

// MIDI::MIDI()
// {
//
// }

void MIDI::noteOn(u8 channel, u8 note, u8 velocity)
{

  #ifdef DEBUG
  CompositeSerial.print("MIDI In \t");
  CompositeSerial.print(channel);
  CompositeSerial.print("\t");
  CompositeSerial.print(note);
  CompositeSerial.print("\t");
  CompositeSerial.println(velocity);
  #endif

  //LED.on(channel);

  // if(channel == 5)
  //   channel = 1; //unipad support
  if(channel = 0)
  {
    if(velocity == 0)
    {
      MIDI::noteOff(channel, note, velocity);
    }

    LED.setPalette(note, channel, velocity);

    offMap[note] = -1;
  }
}

void MIDI::noteOff(u8 channel, u8 note, u8 velocity)
{
  offMap[note] = 2;
}

void MIDI::handleNoteOff(unsigned int channel, unsigned int note, unsigned int velocity)
{
  MIDI::noteOff(channel,note,velocity);
  //USBMIDI.sendNoteOff(channel,note,velocity);
  //leds[IndexInKeyMap(note)] = 0;
  //CompositeSerial.println(channel + " off " + note + " " + velocity);
}

void MIDI::handleNoteOn(unsigned int channel, unsigned int note, unsigned int velocity)
{
  MIDI::noteOn(channel,note,velocity);
  //USBMIDI.sendNoteOn(channel,note,velocity);
  //leds[IndexInKeyMap(note)] = colour[channel][velocity];
}

void MIDI::offScan()
{
  for(u8 note = 0; note < 128; note ++)
  {
    if(offMap[note] != -1)
    {
      if(offMap[note] == 0)
      LED.off(note);
    }
    offMap[note] --;
  }
}
