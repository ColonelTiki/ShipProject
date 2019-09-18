#include <FastLED.h>

#define DATA_PIN 5
#define NUM_LEDS 26
#define CHIPSET WS2811
#define COLOR_ORDER GRB
#define FRAMES_PER_SECOND 24


CRGBArray<NUM_LEDS> leds;

CRGBSet L3(leds(0,2)); //Bottom Floor, Right Building
CRGBSet L4(leds(3,3)); //Top Floor, Right Building
CRGBSet L5(leds(4,4)); //Rotunda Window, Right Side
CRGBSet Sh6(leds(5,5)); //ShipTop - Top Window
CRGBSet Sh5(leds(6,6)); //ShipTop - Middle Window
CRGBSet Sh4(leds(7,7)); //ShipTop - Bottom Window
CRGBSet L1(leds(8,11)); //Top Floor, Left Building
CRGBSet L2(leds(12,12)); //Bottom Floor, Left Building
CRGBSet Sh2(leds(13,15)); //Ship - Captain's Left
CRGBSet Sh3(leds(16,18)); //Ship - Captain's Right
CRGBSet Sh1(leds(19,25)); //Ship - Hold

int hue_start = 0;

void setup() {
 FastLED.addLeds<CHIPSET, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS);
 FastLED.setBrightness(64);
}

void loop() {
 
  
  L1 = CRGB::Red;
  L2 = CRGB::Orange;
  //L3 = CRGB::DeepPink;
  
  fill_rainbow( L3, 3, hue_start, 24);
  L4 = CRGB::Orange;
  L5 = CRGB::Yellow;
  Sh1 = CRGB::Blue;
  Sh2 = CRGB::Yellow;
  Sh3 = CRGB::Green;
  Sh4 = CRGB::Purple;
  Sh5 = CRGB::Blue;
  Sh6 = CRGB::Green;
  
FastLED.show();
hue_start++;
if (hue_start > 255) { hue_start = 0; }
FastLED.delay(1000/FRAMES_PER_SECOND);
}
