#include <FastLED.h>

#define DATA_PIN 5
#define NUM_LEDS 150
#define CHIPSET WS2812B
#define COLOR_ORDER GRB
#define FRAMES_PER_SECOND 12

int hue_start = 0;
int jitter = 128;
int potpin = 0;
int val;

CRGBArray<NUM_LEDS> leds;

CRGBSet L3(leds(0,2)); //Bottom Floor, Right Building
CRGBSet L4(leds(3,3)); //Top Floor, Right Building
CRGBSet L5(leds(4,4)); //Rotunda Window, Right Side
CRGBSet Sh6(leds(5,5)); //ShipTop - Bottom Window
CRGBSet Sh5(leds(6,6)); //ShipTop - Middle Window
CRGBSet Sh4(leds(7,7)); //ShipTop - Top Window
CRGBSet L1(leds(8,11)); //Top Floor, Left Building
CRGBSet L2(leds(12,12)); //Bottom Floor, Left Building
CRGBSet Sh2(leds(13,15)); //Ship - Captain's Left
CRGBSet Sh3(leds(16,18)); //Ship - Captain's Right
CRGBSet Sh1(leds(19,25)); //Ship - Hold

CRGBPalette16 Ocean( OceanColors_p );
CRGBPalette16 Lava ( LavaColors_p );
CRGBPalette16 Forest ( ForestColors_p );
CRGBPalette16 Cloud ( CloudColors_p );

void setup() {
 FastLED.addLeds<CHIPSET, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS);
 Serial.begin(9600);
 }

void loop() {

val = analogRead(potpin);
val = map(val, 0, 1023, 0, 255);
FastLED.setBrightness(52);
 
 fill_solid( leds, NUM_LEDS, CRGB::Black); //Clear it every cycle just to be sane

// Assign colors
  
  //L3 = CRGB::Green;
  //fill_palette(L3, 3, hue_start, 4, Forest, 255, LINEARBLEND);
  
  //L4 = CRGB::Purple;
  
  //L5 = CRGB::Blue;
  
  //Sh4 = CRGB::Purple;

  //Sh5 = CRGB::Blue;
  
  //Sh6 = CRGB::Green;

  //L1 = CRGB::Green;
 
  //L2 = CRGB::Yellow;
    
  //Sh2 = CRGB::Orange;
  //fill_palette( Sh2, 3, jitter, 16, Lava, 255, LINEARBLEND );
  
  //Sh3 = CRGB::Orange;
  //fill_palette( Sh3, 3, jitter, 16, Lava, 255, LINEARBLEND );

  //Sh1 = CRGB::Red;
  //fill_palette( Sh1, 7, jitter, 8, Lava, 255, LINEARBLEND );


  
    fill_rainbow ( leds, NUM_LEDS, hue_start, 1);
  

  
  
// end Assign colors
  
FastLED.show();

hue_start++;
if (hue_start > 255) { hue_start = 0; }

if (random(2) == 0) { jitter++; } else { jitter--; }
if ( jitter > 255) { jitter = 0; }
if ( jitter < 0 ) { jitter = 255; }

FastLED.delay(1000/FRAMES_PER_SECOND);
}
