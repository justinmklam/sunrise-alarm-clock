#include "FastLED.h"

// How many leds in your strip?
#define NUM_LEDS 120

// For led chips like Neopixels, which have a data line, ground, and power, you just
// need to define DATA_PIN.  For led chipsets that are SPI based (four wires - data, clock,
// ground, and power), like the LPD8806 define both DATA_PIN and CLOCK_PIN
#define DATA_PIN 6
#define CLOCK_PIN 13
#define LED_DELAY 50
#define BRIGHTNESS 255

// Define the array of leds
CRGB leds[NUM_LEDS];

void setup() { 
  delay(3000); // 3 second delay for recovery
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(BRIGHTNESS);
}

void loop() { 
//  Sunrise();
//  fill();
  huehuehue();
}

// turn on the leds like a sunrise red - orange - white (brightest)
void Sunrise()
{
  // sunrise
  CRGB SunColors[3];
  SunColors[0] = CRGB::Red;
  SunColors[1] = CRGB::Orange;
  SunColors[2] = CRGB::Yellow;
  
  for(int c = 0; c<3; c++ )
  {
    for(int i = 0; i < NUM_LEDS; i++ )
    {  
      leds[i] = SunColors[c];
      FastLED.show();
      delay(25);
    }
  }
}

void fill()
{
  uint32_t ledarr = 4;
  CRGB Colors[ledarr];
  Colors[0] = CRGB::Red;
  Colors[1] = 0xF5B041;
  Colors[2] = CRGB::Yellow;
  Colors[3] = CRGB::Turquoise;

  for(int i=0; i < ledarr; i++)
  {
    fill_solid(leds, NUM_LEDS, Colors[i]);
    FastLED.show();
    delay(LED_DELAY);
  }
//      fill_solid(leds, NUM_LEDS, CRGB::Red); // Set all to red.
//      FastLED.show();
//      delay(LED_DELAY);
//      fill_solid(leds, NUM_LEDS, CRGB::Green); // Set all to red.
//      FastLED.show();
//      delay(LED_DELAY);
//      fill_solid(leds, NUM_LEDS, CRGB::Orange); // Set all to red.
//      FastLED.show();
//      delay(LED_DELAY);
}

void huehuehue()
{
  static uint8_t hue = 0;
  static uint8_t saturatn = 255;
  static uint8_t val = 0;
  static uint8_t state = 0;
  
  static uint8_t direction = 1;
  static uint8_t delay_scale_factor = 1;

  switch(state) {
	  default:	// black
		FastLED.showColor(CRGB::Black);
		val = 0;
		hue = 0;
		saturatn = 255;
		state++;
		direction = 1;
		delay(1000);
		delay_scale_factor = 1;
		break;
    
	case 1:
		val = 1;
		for(uint8_t i=0; i < NUM_LEDS; i++) {
//			for(uint8_t j=0; j < 10; j++) {
        if(direction > 0)
				  leds[i] = CHSV(hue, saturatn, val);
         else
          leds[i] = CRGB::Black;
//			}
			FastLED.show();
			delay(LED_DELAY);
//			i += 10;
		}
		state += direction;
		break;
    
	case 2:		// ramp up brightness
		delay_scale_factor = 1;
    FastLED.showColor(CHSV(hue, saturatn, val));
	  val += direction;
      if(val >= 255) {
        state += direction;
	  }
      break;
      
   case 3:		// change between red and yellow
		delay_scale_factor = 3;
      FastLED.showColor(CHSV(hue, saturatn, 255));
	  hue += direction;
      if(hue > 128) {
        state += direction;
	  }
      break;
      
    case 4:		// change between yellow and white
		delay_scale_factor = 1;
      FastLED.showColor(CHSV(hue, saturatn, 255));
	  saturatn -= direction;
	  
      if(saturatn <= 245) {
		  state += direction;
		direction = -1;
		delay(1000);
	  }
      break;
	  
	case 5:		// change between white and yellow
		delay_scale_factor = 1;
		FastLED.showColor(CHSV(hue, saturatn, 255));
		saturatn -= direction;
		if (saturatn >= 255) {
			state += 2*direction;
		}
  }

  delay(LED_DELAY*delay_scale_factor);
}
