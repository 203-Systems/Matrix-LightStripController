#include "LED.h"
// #include <FastLED.h>

#ifdef DEBUG
#include <USBComposite.h>
#endif

LED::LED()
{
  //LED::setBrightness(brightness);
  // if(POWERCORD)
  //{
  //   CRGB pc_leds[NUM_POWERCORD_LEDS];
  //   FastLED.addLeds<WS2812B, powercord_pin>(pc_leds, NUM_POWERCORD_LEDS);
  // }
}

void LED::init()
{
  switch(led_pin)
  {
    case 29:
    FastLED.addLeds<NEOPIXEL, 29>(leds, NUM_LEDS);
    break;
  }

  FastLED.setBrightness(brightness);
  FastLED.setCorrection(led_color_correction);
  FastLED.setTemperature(0xFFFFFFFF);
  //FastLED.setMaxRefreshRate(fps);
  //LED::dynamicBrightness(max_mAh);
}

void LED::setBrightness(u8 b)
{
  FastLED.setBrightness(b);
  //setBrightnesss(b);
}

void LED::dynamicBrightness(u16 mah)
{
  FastLED.setMaxPowerInVoltsAndMilliamps(5,mah);
}

void LED::fill(u32 WRGB, bool overlay /*= false*/)
{
  //fill_solid(leds,NUM_TOTAL_LEDS,CRGB::Black);
  for(int i = 0; i < NUM_LEDS; i++)
  {
      leds[i] = WRGB;
  }
  //FastLED.show();
}

// void LED::setLED(INDEXMODE indexmode, LEDMODE ledmode, u8 xy = 0, u32 p1 = 0, u8 p2 = 0, u8 p3 = 0, u8 p4 = 0)
// {
//   u8 index = x;
//   if(ledmode == XY)
//   u8 index = xyToIndex(xy);
//
//   switch (ledmode)
//   {
//     case off:
//     LED::Off(index);
//     break;
//     case on:
//     LED::On(index);
//     break;
//     case w:
//     LED::setW(index, p1);
//     break;
//     case rgb:
//     LED::setRGB(index, p1, p2, p3);
//     break;
//     case wrgb:
//     LED::setWRGB(index, p1, p2, p3, p4);
//     break;
//     case hex:
//     LED::setHEX(index, p1);
//     break;
//     case palette:
//     LED::setPalette(index, p1, p2);
//     break;
//   }
// }

// Index
void LED::off(s16 index, bool overlay /*= false*/)
{
  LED::setHEX(index, 0, overlay);
}

void LED::on(s16 index, bool overlay /*= false*/)
{
  LED::setHEX(index, 0xFFFFFFFF, overlay);
}

void LED::setW(s16 index, u8 w, bool overlay /*= false*/)
{
  LED::setHEX(index, w * 0x10000 + w * 0x100 + w, overlay);
}

void LED::setRGB(s16 index, u8 r, u8 g, u8 b, bool overlay /*= false*/)
{
  LED::setHEX(index, r * 0x10000 + g * 0x100 + b, overlay);
}

void LED::setWRGB(s16 index, u8 w, u8 r, u8 g, u8 b, bool overlay /*= false*/)
{
  LED::setHEX(index, w * 0x1000000 + r * 0x10000 + g * 0x100 + b, overlay);
}

void LED::setHEX(s16 index, u32 hex, bool overlay /*= false*/, bool ignore_gamma /*= false*/)
{
  #ifdef DEBUG
  CompositeSerial.print("LED Index \t");
  CompositeSerial.print(index);
  CompositeSerial.print("\t");
  CompositeSerial.println(hex, HEX);
  #endif

  if(index < 0)
  return;

  leds[index] = hex;
}

void LED::setPalette(s16 index, u8 pick_palette, u8 colour, bool overlay /*= false*/)
{
  LED::setHEX(index, palette[pick_palette][colour], overlay, true);
}


//Processing

void LED::update()
{
  FastLED.show();
}
