#include "Numbers.h"

uint8_t** PixelNumbers::getNum(uint8_t value)
{
	uint8_t num[CHAR_WIDTH][CHAR_HEIGHT];

	switch (value) {
	case 0:
		//return one;
		break;
	case 1:
		break;
	}
	return uint8_t();
}

uint8_t PixelNumbers::zero[CHAR_HEIGHT][CHAR_WIDTH] = {
	{ 0,1,1,1 },
	{ 0,1,0,1 },
	{ 0,1,0,1 },
	{ 0,1,0,1 },
	{ 0,1,1,1 }
};

uint8_t PixelNumbers::one[CHAR_HEIGHT][CHAR_WIDTH] = {
	{ 0,0,0,1 },
	{ 0,0,0,1 },
	{ 0,0,0,1 },
	{ 0,0,0,1 },
	{ 0,0,0,1 }
};

uint8_t PixelNumbers::two[CHAR_HEIGHT][CHAR_WIDTH] = {
	{ 0,1,1,1 },
	{ 0,0,0,1 },
	{ 0,1,1,1 },
	{ 0,1,0,0 },
	{ 0,1,1,1 }
};

uint8_t PixelNumbers::three[CHAR_HEIGHT][CHAR_WIDTH] = {
	{ 0,1,1,1 },
	{ 0,0,0,1 },
	{ 0,1,1,1 },
	{ 0,0,0,1 },
	{ 0,1,1,1 }
};

uint8_t PixelNumbers::four[CHAR_HEIGHT][CHAR_WIDTH] = {
	{ 0,1,0,1 },
	{ 0,1,0,1 },
	{ 0,1,1,1 },
	{ 0,0,0,1 },
	{ 0,0,0,1 }
};

uint8_t PixelNumbers::five[CHAR_HEIGHT][CHAR_WIDTH] = {
	{ 0,1,1,1 },
	{ 0,1,0,0 },
	{ 0,1,1,1 },
	{ 0,0,0,1 },
	{ 0,1,1,1 }
};

uint8_t PixelNumbers::six[CHAR_HEIGHT][CHAR_WIDTH] = {
	{ 0,1,1,1 },
	{ 0,1,0,0 },
	{ 0,1,1,1 },
	{ 0,1,0,1 },
	{ 0,1,1,1 }
};

uint8_t PixelNumbers::seven[CHAR_HEIGHT][CHAR_WIDTH] = {
	{ 0,1,1,1 },
	{ 0,0,0,1 },
	{ 0,0,0,1 },
	{ 0,0,0,1 },
	{ 0,0,0,1 }
};

uint8_t PixelNumbers::eight[CHAR_HEIGHT][CHAR_WIDTH] = {
	{ 0,1,1,1 },
	{ 0,1,0,1 },
	{ 0,1,1,1 },
	{ 0,1,0,1 },
	{ 0,1,1,1 }
};

uint8_t PixelNumbers::nine[CHAR_HEIGHT][CHAR_WIDTH] = {
	{ 0,1,1,1 },
	{ 0,1,0,1 },
	{ 0,1,1,1 },
	{ 0,0,0,1 },
	{ 0,1,1,1 }
};
