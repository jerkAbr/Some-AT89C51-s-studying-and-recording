#include <REGX52.H>
#include <DELAY.H>

unsigned char Key() {
	unsigned char KeyNumber = 0;

	if (P3_1 == 0) {
		Delay1ms(20);
		while (P3_1 == 0);
		Delay1ms(20);
		KeyNumber = 1;
		
	} else if (P3_0 == 0) {
		Delay1ms(20);
		while (P3_0 == 0);
		Delay1ms(20);
		KeyNumber = 2;
		
	} else if (P3_2 == 0) {
		Delay1ms(20);
		while (P3_2 == 0);
		Delay1ms(20);
		KeyNumber = 3;
		
	} else if (P3_3 == 0) {
		Delay1ms(20);
		while (P3_3 == 0);
		Delay1ms(20);
		KeyNumber = 4;
		
	} else {
		KeyNumber = 0; //Not press any key
	}

	return KeyNumber;
}