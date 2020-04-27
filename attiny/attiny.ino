#include <avr/interrupt.h>
#include <avr/sleep.h>


// Pin 4 has an mosfet connected on most Arduino boards.
int mosfet = 4;
// interrupt counter
int count = 0;

ISR(WDT_vect) {
  digitalWrite(mosfet, LOW);   // turn the mosfet off - keep it off
  count = count +1;
  if (count >15*10)  //15*8s=120s=2min  2*10=20min
  {
    digitalWrite(mosfet, HIGH);   // turn the mosfet on (HIGH is the voltage level) till the next interrupt
    //delay(7000);
    count = 0;
  }

}

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(mosfet, OUTPUT);   

  (ADCSRA &= ~(1<<ADEN)); // disable ADC (before power-off) // ADC uses ~320uA

  digitalWrite(mosfet, HIGH);   // turn the mosfet on (HIGH is the voltage level)
  delay(7000);
  count = 0;

  //SET timer for 8s
  WDTCR |= (1<<WDP3 )|(0<<WDP2 )|(0<<WDP1)|(1<<WDP0); // 8s

  // Enable watchdog timer interrupts
  WDTCR |= (1<<WDTIE);
  sei(); // Enable global interrupts 
  // Use the Power Down sleep mode
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);

  for (;;) {
    sleep_mode();   // go to sleep and wait for interrupt...
  }
}

// the loop routine runs over and over again forever:
void loop() {
  // wait for a second

}

/*
Values for the watchdok interrupt
 16MS   (0<<WDP3)|(0<<WDP2)|(0<<WDP1)|(0<<WDP0) 
 32MS   (0<<WDP3)|(0<<WDP2)|(0<<WDP1)|(1<<WDP0) 
 64MS   (0<<WDP3)|(0<<WDP2)|(1<<WDP1)|(0<<WDP0) 
 125MS  (0<<WDP3)|(0<<WDP2)|(1<<WDP1)|(1<<WDP0) 
 250MS  (0<<WDP3)|(1<<WDP2)|(0<<WDP1)|(0<<WDP0) 
 500MS  (0<<WDP3)|(1<<WDP2)|(0<<WDP1)|(1<<WDP0) 
 1S     (0<<WDP3)|(1<<WDP2)|(1<<WDP1)|(0<<WDP0) 
 2S     (0<<WDP3)|(1<<WDP2)|(1<<WDP1)|(1<<WDP0) 
 4S     (1<<WDP3)|(0<<WDP2)|(0<<WDP1)|(0<<WDP0) 
 8S     (1<<WDP3)|(0<<WDP2)|(0<<WDP1)|(1<<WDP0) 
 */
