#include "FastLED.h"

// How many leds in your strip?
#define NUM_LEDS 120

// For led chips like Neopixels, which have a data line, ground, and power, you just
// need to define DATA_PIN.  For led chipsets that are SPI based (four wires - data, clock,
// ground, and power), like the LPD8806 define both DATA_PIN and CLOCK_PIN
#define DATA_PIN 6
#define CLOCK_PIN 13
#define LED_DELAY 13
#define BRIGHTNESS 255
#define HUE 23
#define SATURATION 245

// Normalizing parameters to make each transition take the same amount of time. Use spreadsheet to determine these scaling factors
#define TRANSITION_OFF 1
#define TRANSITION_BRIGHTNESS 1
#define TRANSITION_HUE 11.04
#define TRANSITION_SATURATN 25.4

// Define the array of leds
CRGB leds[NUM_LEDS];

void setup() { 
  delay(3000); // 3 second delay for recovery
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(BRIGHTNESS);
}

void loop() { 
  sunrise(2);
}

// Type 1: Forward only, Type 2: Forward and reverse
void sunrise(uint8_t type)
{
  static uint8_t hue = 0;
  static uint8_t saturatn = 255;
  static uint8_t val = 0;
  static uint8_t state = 0;
  
  static int8_t direction = 1;
  static float delay_scale_factor = 1;

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
    
	case 1:		// slowly turn on from black to red
		val = 1;
		delay_scale_factor = TRANSITION_OFF;
		if (direction > 0)
			wipeByRow(CHSV(hue, saturatn, val), LED_DELAY*delay_scale_factor);
		else
			wipeByRow(CRGB::Black, LED_DELAY*delay_scale_factor);

		state += direction;
		break;
    
	case 2:		// ramp up brightness
		delay_scale_factor = TRANSITION_BRIGHTNESS;
		FastLED.showColor(CHSV(hue, saturatn, val));
		val += direction;

		if(val >= BRIGHTNESS) {
			state += direction;
		}
		break;
      
   case 3:		// change between red and yellow
		delay_scale_factor = TRANSITION_HUE;
		FastLED.showColor(CHSV(hue, saturatn, BRIGHTNESS));
		hue += direction;

		if(hue > HUE) {
			state += direction;
		}
		break;
      
    case 4:		// change between yellow and white
		delay_scale_factor = TRANSITION_SATURATN;
		FastLED.showColor(CHSV(hue, saturatn, BRIGHTNESS));
		saturatn -= direction;
	  
		// forward direction
		if(direction > 0 && saturatn <= SATURATION) {
			switch (type) {
			case 1:		// forward only
				state += direction;
				break;
			case 2:		// forward and reverse
				direction = -1;
				delay(1000);
			}
		}
		// reverse direction
		else if (direction < 0 && saturatn >= 255) {
			state += direction;
		}
		break;

	case 5:
		// do nothing
		break;
  }

  if (state != 1)
	delay(LED_DELAY*delay_scale_factor);
}

void wipeByRow(const CRGB &color, uint8_t led_delay) {
	uint8_t leds_per_row = 10;

	for (uint8_t i = 0; i < NUM_LEDS; i++) {
		// turn on leds by row
		for (uint8_t j = 0; j < leds_per_row; j++) {
			leds[i + j] = color;
		}
		FastLED.show();
		delay(led_delay);
		i += leds_per_row;
	}
}