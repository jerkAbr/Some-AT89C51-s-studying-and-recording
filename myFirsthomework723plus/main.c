#include <REGX52.H>
#include <INTRINS.H>
#include <DELAY.H>
#include <KEY.H>

unsigned char num;


void main() {
	unsigned char i = 0;
	P2 = ~ 0x00; //Always turn down
	//Timer2Init();
	//EA = 1;
	//EX0 = 1;
	//IT0 = 0;

	while (1) {
		num = Key();

		if (num == 1) {  //==key1==
			Delay1ms(20);  //Delay for debounce, and the same goes for other keys
			while (P3_0 == 0);
			Delay1ms(20);

			P2_0 = ~ P2_0; //Turn down the light
		}


		if (num == 2) {  //==key2==
			Delay1ms(20);
			P2 = _crol_(P2, 1);  //it use crol funtion to move the LED light
			Delay1ms(20);
		}


		if (num == 3) {  //==key3==
			Delay1ms(20);
			P2 = _cror_(P2, 1);  //it use cror funtion to move the LED light
			Delay1ms(20);
		}


		if (num == 4) {  //==key4==
			while (1) {
				num = Key();
				P2 = _crol_(P2, 1);  //it use _crol_ funtion to move the LED light
				Delay1ms(450);
				
//==INTENTION== : When you press key1 while running the stream, the code here ensures that you can still add new lights//
				
				if (P3_1 == 0) {  //When you press key 4 & 1, this code can help you works well, This feature is not requested in the video but I tried to add it anyway
					Delay1ms(10);
					while (P3_1 == 0);
					Delay1ms(10);

					P2_7 = ~ P2_7;     //By the way, this position must be recaculated
					if (num == 4) {
						break;
					}
				}
				
//==INTENTION== : When you press key1 while running the stream, the code here ensures that you can still add new lights//
				
				if (num != 0) {
					break;
				}
			}
		}


	}  //firstWhile
}  //mainFuntion






//Thanks for watching and hope you have a good day , and this code was writen by LvZongyue on 23/7/2022