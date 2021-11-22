#define F_CPU 3686000UL
#include <avr/io.h>
#include <stdint.h>
#include <avr/interrupt.h>
#include "lcd.h"


void printmylcd(uint8_t value);
void initialise(void);

volatile uint8_t state = 1;
volatile uint16_t raw_value = 0;
volatile uint16_t value = 34;

int main(void)
{
	
	//initialise lcd
	lcd_init();
	lcd_cursor(false, false); /* cursor uit */
	
	initialise();
	
	//printmylcd(0);
	
	
	
	
    while (1) {
		/*iets*/
		if(PD6 == 1 && state == 0){
			//Wat is de waarde
			raw_value = TCNT1;
			
			//Reset de timer
			TCNT1 = 0;
			state = 1;
		}
		
 		if(state == 1){
			//bereken waardes en schrijf naar lcd
			//printmylcd(156);
			
			//char buffer[6];
			//snprintf(buffer, sizeof buffer, "%4d",value);
	
			lcd_cls();
			lcd_puts("De periodetijd =");
			lcd_goto(1,0);
			//lcd_puts(buffer);
			lcd_puts(" uS");
	
			state = 1;
		}
		
		if(PD6 ==0 && state == 2){
			state = 0;
		}
		
    }
	return 0;
}



void initialise(void){
	
	//Initialise timer 0
	TCNT0 = 0;
	TCCR0 = (1<<WGM01) | (1<<CS01) | (1<<CS00) | (1<<COM00);
	OCR0 = 255; //Compare waarde
			
	//Initialise timer 1
	TCNT1 = 0;
	TCCR1B = (1<<CS10) ;
	
		
	//Set juiste interupts aan
	TIMSK |= (1<<OCIE0); 
		
	sei(); //zet interupts aan
	
	
	
}

/*
void printmylcd(uint16_t value){
	char buffer[6];
	lcd_home();
	snprintf(buffer, sizeof buffer, "%4d",value);
	
	lcd_cls();
	lcd_puts("De periodetijd =");
	lcd_goto(1,0);
	lcd_puts(buffer);
	lcd_puts(" uS");
}
*/