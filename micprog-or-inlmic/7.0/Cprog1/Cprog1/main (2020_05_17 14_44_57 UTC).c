#include <avr/io.h>
#include <stdint.h>
#include <util/delay.h>

void wait(void) {
	uint8_t i;
//	for (i = 0; i < 5; ++i)
	_delay_ms(80);
}

int main(void) {
	void wait(void);
	uint8_t c1, c2, i;
	uint8_t knop = 0;
	DDRB = 0xFF;
	DDRA = 0x00;
	
	while (1) {
		//SWITCH VOOR KNOPPEN
		if(PINA == 0x7f)
		{
			if(knop == 0)
			{
				knop = 1;
			} else {
				knop = 0;
			}
		}
		if (knop == 1)
		{
			c1 = 0x10; //1000 0000
			c2 = 0x08; //0000 1000
			for (i = 0; i < 4; i++) {
				wait();
				PORTB = ~(c1 | c2);
				c1 <<= 1;
				c2 >>= 1;
			}
		} else {
			c1 = 0x80;
			c2 = 0x01;
			for (i = 0; i < 4; i++) {
				wait();
				PORTB = ~(c1 | c2);
				c1 >>= 1;
				c2 <<= 1;
			}
		}
	}
	return 0;
}

