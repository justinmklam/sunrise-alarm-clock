#ifndef NUMBERS
#define NUMBERS

#define CHAR_HEIGHT 5
#define CHAR_WIDTH 4

//uint8_t* getNum(uint8_t num) {
//	switch (num) {
//	case 0:
//		return *zero;
//	}
//}

uint8_t zero[CHAR_HEIGHT][CHAR_WIDTH] = {
	{ 0,1,1,1 },
	{ 0,1,0,1 },
	{ 0,1,0,1 },
	{ 0,1,0,1 },
	{ 0,1,1,1 }
};

uint8_t one[CHAR_HEIGHT][CHAR_WIDTH] = {
	{ 0,0,0,1 },
	{ 0,0,0,1 },
	{ 0,0,0,1 },
	{ 0,0,0,1 },
	{ 0,0,0,1 }
};

uint8_t two[CHAR_HEIGHT][CHAR_WIDTH] = {
	{ 0,1,1,1 },
	{ 0,0,0,1 },
	{ 0,1,1,1 },
	{ 0,1,0,0 },
	{ 0,1,1,1 }
};

uint8_t three[CHAR_HEIGHT][CHAR_WIDTH] = {
	{ 0,1,1,1 },
	{ 0,0,0,1 },
	{ 0,1,1,1 },
	{ 0,0,0,1 },
	{ 0,1,1,1 }
};

uint8_t four[CHAR_HEIGHT][CHAR_WIDTH] = {
	{ 0,1,0,1 },
	{ 0,1,0,1 },
	{ 0,1,1,1 },
	{ 0,0,0,1 },
	{ 0,0,0,1 }
};

uint8_t five[CHAR_HEIGHT][CHAR_WIDTH] = {
	{ 0,1,1,1 },
	{ 0,1,0,0 },
	{ 0,1,1,1 },
	{ 0,0,0,1 },
	{ 0,1,1,1 }
};

uint8_t six[CHAR_HEIGHT][CHAR_WIDTH] = {
	{ 0,1,1,1 },
	{ 0,1,0,0 },
	{ 0,1,1,1 },
	{ 0,1,0,1 },
	{ 0,1,1,1 }
};

uint8_t seven[CHAR_HEIGHT][CHAR_WIDTH] = {
	{ 0,1,1,1 },
	{ 0,0,0,1 },
	{ 0,0,0,1 },
	{ 0,0,0,1 },
	{ 0,0,0,1 }
};

uint8_t eight[CHAR_HEIGHT][CHAR_WIDTH] = {
	{ 0,1,1,1 },
	{ 0,1,0,1 },
	{ 0,1,1,1 },
	{ 0,1,0,1 },
	{ 0,1,1,1 }
};

uint8_t nine[CHAR_HEIGHT][CHAR_WIDTH] = {
	{ 0,1,1,1 },
	{ 0,1,0,1 },
	{ 0,1,1,1 },
	{ 0,0,0,1 },
	{ 0,1,1,1 }
};

uint8_t empty[CHAR_HEIGHT][CHAR_WIDTH] = {
	{ 0,0,0,0 },
	{ 0,0,0,0 },
	{ 0,0,0,0 },
	{ 0,0,0,0 },
	{ 0,0,0,0 }
};


#endif