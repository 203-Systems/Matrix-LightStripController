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
  // for(u8 n; n < nums_led_channel_available; n++)
  // {
  //   switch(led_pins[n])
  //   {
  //     case PB6:
  //     FastLED.addLeds<NEOPIXEL, PB6>(leds[n], NUM_LEDS);
  //     break;
  //     case PB11:
  //     FastLED.addLeds<NEOPIXEL, PB11>(leds[n], NUM_LEDS);
  //     break;
  //     case PA5:
  //     FastLED.addLeds<NEOPIXEL, PA5>(leds[n], NUM_LEDS);
  //     break;
  //     case PB14:
  //     FastLED.addLeds<NEOPIXEL, PB14>(leds[n], NUM_LEDS);
  //     break;
  //   }
  // }

//For STLINK V2
  //pinMode(PB10, INPUT_FLOATING);
  FastLED.addLeds<NEOPIXEL, PB6>(leds[0], NUM_LEDS);
  FastLED.addLeds<NEOPIXEL, PB11>(leds[1], NUM_LEDS);
  FastLED.addLeds<NEOPIXEL, PA5>(leds[2], NUM_LEDS);
  FastLED.addLeds<NEOPIXEL, PB14>(leds[3], NUM_LEDS);


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

void LED::fill(u32 WRGB)
{
  fill_solid(leds[0], 128, WRGB);
  fill_solid(leds[1], 128, WRGB);
  fill_solid(leds[2], 128, WRGB);
  fill_solid(leds[3], 128, WRGB);
}

void LED::off(u8 channel, s16 index)
{
  LED::setHEX(channel, index, 0);
}

void LED::on(u8 channel, s16 index)
{
  LED::setHEX(channel, index, 0xFFFFFFFF);
}

void LED::setW(u8 channel, s16 index, u8 w)
{
  LED::setHEX(channel, index, w * 0x10000 + w * 0x100 + w);
}

void LED::setRGB(u8 channel, s16 index, u8 r, u8 g, u8 b)
{
  LED::setHEX(channel, index, r * 0x10000 + g * 0x100 + b);
}

void LED::setHEX(u8 channel, s16 index, u32 hex)
{
  #ifdef DEBUG
  CompositeSerial.print("LED Index \t");
  CompositeSerial.print(index);
  CompositeSerial.print("\t");
  CompositeSerial.println(hex, HEX);
  #endif

  if(index < 0)
  return;

  leds[channel][index] = hex;
}

void LED::setPalette(u8 channel, s16 index, u8 pick_palette, u8 colour)
{
  LED::setHEX(channel, index, palette[pick_palette][colour]);
}


//Processing

void LED::update()
{
  FastLED.show();
}

void LED::rainbow()
{
  for(int h = 0; h < 256; h += 5)
  {
    fill_rainbow(leds[0], NUM_LEDS, h, 5);
    fill_rainbow(leds[1], NUM_LEDS, h, 5);
    fill_rainbow(leds[2], NUM_LEDS, h, 5);
    fill_rainbow(leds[3], NUM_LEDS, h, 5);
    LED::update();
    delay(10);
  }
  LED::fill(0);
  LED::update();
}
