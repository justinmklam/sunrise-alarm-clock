#include "FastLED.h"
#include "Numbers.h"

// How many leds in your strip?
#define NUM_LEDS 120
#define LEDS_PER_ROW 10

// For led chips like Neopixels, which have a data line, ground, and power, you just
// need to define DATA_PIN.  For led chipsets that are SPI based (four wires - data, clock,
// ground, and power), like the LPD8806 define both DATA_PIN and CLOCK_PIN
#define DATA_PIN 6
#define CLOCK_PIN 13
#define LED_DELAY 13
#define BRIGHTNESS 255
#define HUE 23
#define SATURATION 245

#define CHAR_OFFSET 3

// Normalizing parameters to make each transition take the same amount of time. Use spreadsheet to determine these scaling factors
#define TRANSITION_OFF 1
#define TRANSITION_BRIGHTNESS 1
#define TRANSITION_HUE 11.04
#define TRANSITION_SATURATN 25.4

// Global variables
uint8_t hue, saturatn, val;

// Define the array of leds
CRGB leds[NUM_LEDS];

// Function prototypes
void wipeByRow(const CRGB &color, uint8_t led_delay, bool omitLastRow=true);

void setup() { 
	Serial.begin(115200);
	delay(1000); // 1 second delay for recovery
	FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
	FastLED.setBrightness(BRIGHTNESS);
}

void loop() { 
	sunrise(1);

	//for (uint8_t i = 0; i <= 9; i++) {
	//	drawNum(i, CRGB::DarkCyan);
	//	delay(250);
	//}
	
}

// Function: Simulates sunrise colours by smoothly transitioning through black (off), red, orange, yellow.
// Params: Type 1 = Forward only, Type 2 = Forward and reverse
void sunrise(uint8_t type)
{
	/*static uint8_t hue, saturatn, val;*/
	static uint8_t state = 0;
	static int8_t direction;
	static float delay_scale_factor;

	switch(state) {
	default:	// turn off lamp
		FastLED.showColor(CRGB::Black);

		// Initialize / reset values
		val = 2;
		hue = 0;
		saturatn = 255;
		direction = 1;
		delay_scale_factor = 1;
		state++;

		delay(1000);

		break;
    
	case 1:		// slowly turn on from black to red (to make transition from off to bright less jarring)
		delay_scale_factor = TRANSITION_OFF;
		if (direction > 0)
			wipeByRow(CHSV(hue, saturatn, 1), LED_DELAY*delay_scale_factor);
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

		delay(LED_DELAY*delay_scale_factor);
		break;
      
   case 3:		// change between red and yellow
		delay_scale_factor = TRANSITION_HUE;
		FastLED.showColor(CHSV(hue, saturatn, BRIGHTNESS));
		hue += direction;

		if(hue > HUE) {
			state += direction;
		}

		delay(LED_DELAY*delay_scale_factor);
		break;
      
    case 4:		// change between yellow and white
		delay_scale_factor = TRANSITION_SATURATN;
		FastLED.showColor(CHSV(hue, saturatn, BRIGHTNESS));
		saturatn -= direction;
	  
		// forward direction
		if(direction > 0 && saturatn <= SATURATION) {
			switch (type) {
			case 1:		// type: forward only
				state += direction;
				break;
			case 2:		// type: forward and reverse
				direction = -1;
				delay(1000);
			}
		}
		// reverse direction
		else if (direction < 0 && saturatn >= 255) {
			state += direction;
		}

		delay(LED_DELAY*delay_scale_factor);
		break;

	case 5:
		turnOff();
		state = 0;
		break;
	}

	//if (state != 1)
		//delay(LED_DELAY*delay_scale_factor);
}

// Function: Turns on leds one row at a time
void wipeByRow(const CRGB &color, uint8_t led_delay, bool omitLastRow) {
	static bool firstpass = true;
	static uint8_t end;

	if (firstpass = true) {
		if (omitLastRow)
			end = NUM_LEDS - LEDS_PER_ROW;
		else
			end = NUM_LEDS;
		firstpass = false;
	}

	for (uint8_t i = 0; i < end; i++) {
		// turn on leds by row
		for (uint8_t j = 0; j < LEDS_PER_ROW; j++) {
			leds[i + j] = color;
		}
		FastLED.show();
		delay(led_delay);
		i += LEDS_PER_ROW;
	}
}

// Fade from current colour to black
void turnOff() {
	uint8_t off_delay = 2;
	uint8_t current_value = val;
	
	while (current_value >= 1) {
		FastLED.showColor(CHSV(hue, saturatn, current_value));
		current_value -= 1;
		//delay(off_delay);
	}
	wipeByRow(CRGB::Black, 0);
}

void drawNum(uint8_t num, const CRGB &color) {
	switch (num) {
	case 0:
		drawPixelNum(zero, color);
		break;
	case 1:
		drawPixelNum(one, color);
		break;
	case 2:
		drawPixelNum(two, color);
		break;
	case 3:
		drawPixelNum(three, color);
		break;
	case 4:
		drawPixelNum(four, color);
		break;
	case 5:
		drawPixelNum(five, color);
		break;
	case 6:
		drawPixelNum(six, color);
		break;
	case 7:
		drawPixelNum(seven, color);
		break;
	case 8:
		drawPixelNum(eight, color);
		break;
	case 9:
		drawPixelNum(nine, color);
		break;
	}
}

void drawPixelNum(uint8_t number[CHAR_HEIGHT][CHAR_WIDTH], const CRGB &color) {
	uint8_t height_offset = 2;
	uint8_t width_offset = 2;
	uint8_t m = CHAR_OFFSET;

	// loop through character matrix
	for (uint8_t i = 0; i < CHAR_HEIGHT; i++) {
		for (uint8_t j = 0; j < CHAR_WIDTH; j++) {
			//Serial.println(m);
			if (number[i][j] == 1) {
				leds[m] = color;
			}
			else {
				leds[m] = CRGB::Black;
			}
			m++;
		}
		m += LEDS_PER_ROW - CHAR_WIDTH;
	}
	FastLED.show();
}

