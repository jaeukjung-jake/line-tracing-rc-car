#include "myArduino.h" 
#include <util/delay.h>

void setup(){
    pinMode(13, OUTPUT); 
}

void loop(){ 
    digitalWrite(13, HIGH); 
    _delay_ms(1000); 
    digitalWrite(13, LOW); 
    _delay_ms(1000);
}

int main(void)
{
    init_ArdPin();
    
    setup();
    while(1)
    {
        loop();
    }
}