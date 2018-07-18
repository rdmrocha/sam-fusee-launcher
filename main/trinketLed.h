#ifndef _TRINKET_LED_H_
#define _TRINKET_LED_H_

#include <Arduino.h>
#include <Adafruit_DotStar.h>

#define LED_CONFIRM_TIME_MS 2000 // How long to show red or green light for success or fail

enum Color {
  BLACK, RED, GREEN, ORANGE, BLUE
};

Adafruit_DotStar strip = Adafruit_DotStar(1, INTERNAL_DS_DATA, INTERNAL_DS_CLK, DOTSTAR_BGR);

void ledInit() 
{
  strip.begin();
  strip.setPixelColor(0, 0, 0, 0);
  strip.show();
}

void setLedColor(Color c) 
{
  switch(c) 
  {
    case BLACK: strip.setPixelColor(0, 0x0); break;
    case ORANGE: strip.setPixelColor(0, 0x402000); break;
    case GREEN: strip.setPixelColor(0, 0x004000); break;
    case RED: strip.setPixelColor(0, 0x400000); break;
    case BLUE: strip.setPixelColor(0, 0x051440); break;
    default: break;
  }
  strip.show();
}

#endif
