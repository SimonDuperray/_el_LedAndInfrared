#include <IRremote.h>

int IR = 11; 
int ledV = 3; 
int ledR = 4; 
IRrecv RCEP(IR);

decode_results RIR;

void setup()
{
 Serial.begin(9600); 
 RCEP.enableIRIn(); 
 pinMode(ledV, OUTPUT);
 pinMode(ledR, OUTPUT);
}

void loop()
{
 if (RCEP.decode(&RIR)) 
 {
 Serial.println(RIR.value, DEC); 
 if (RIR.value == 0xFF6897) 
 {
 digitalWrite(ledV, 0); 
 digitalWrite(ledR, 0);
 }

 if(RIR.value == 0xFF30CF) 
 {
 digitalWrite(ledV, 1);
 }

 if(RIR.value == 0xFF18E7)
 {
 digitalWrite(ledR,1); 
 }
 RCEP.resume();
 }
} 
