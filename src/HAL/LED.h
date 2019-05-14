#ifndef LED_H
#define LED_H

#include <Arduino.h>
#include <FastLED.h>
#include "../Parameter/MatrixVariable.h"
#include "../Parameter/MatrixParameter.h"
#include "../Core/MatrixSystem.h"
//#include "../Components/Color.h"


// enum LEDMoDE{ on, off, w, rgb, wrgb, hex, palette};
// enum INDEXMoDE{ INDEX, XY };

class LED
{
public:
  LED();
  void init();
  void setBrightness(u8 b);
  void dynamicBrightness(u16 mah);
  void fill(u32 WRGB);

  // void setLED(INDEXMoDE indexmode, LEDMoDE ledmode, u8 x1, u8 y1, u32 p1, u8 p2, u8 p3, u8 p4);

  //Raw index - for BottomLED ，PoWERCoRD and raw strap.
  void off(u8 channel, s16 index);
  void on(u8 channel, s16 index);
  void setW(u8 channel, s16 index, u8 w);
  void setRGB(u8 channel, s16 index, u8 r, u8 g, u8 b);
  void setHEX(u8 channel, s16 index, u32 hex);
  void setPalette(u8 channel, s16 index, u8 pick_palette, u8 colour);

  //Processing
  void update();
  void rainbow();

private:
  CRGB leds[NUM_LED_STRIP][NUM_LEDS];
};

//extern LED LED;

#endif
