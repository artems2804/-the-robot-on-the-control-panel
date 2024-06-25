#include "IRremote.hpp"



const int motorA1  = 9;  // L298N'in IN3
  const int motorA2  = 10;  // L298N'in IN1
  const int motorB1  = 11; // L298N'in IN2
  const int motorB2  = 12; 
  int vSpeed=255;
  
IRrecv irrecv(6);
decode_results results;
int flag=0;
void setup() {
   Serial.begin(9600);
   irrecv.enableIRIn();
   pinMode(13, OUTPUT);
   digitalWrite(13, LOW);
   pinMode(motorA1, OUTPUT);
    pinMode(motorA2, OUTPUT);
    pinMode(motorB1, OUTPUT);
    pinMode(motorB2, OUTPUT);    
   
}

void loop() {
   if (irrecv.decode(&results)){
    Serial.println(results.value);
    if (results.value == 16718055){
       if (flag == 1){
        analogWrite(motorA1, vSpeed); analogWrite(motorA2, 0);
        analogWrite(motorB1, vSpeed);      analogWrite(motorB2, 0);  flag = 0; delay(300);}
        else
        {analogWrite(motorA1, 0);   analogWrite(motorA2, vSpeed); 
        analogWrite(motorB1, 0);   analogWrite(motorB2, vSpeed);  flag = 1; delay(300);}
      }
      else if(results.value == 4294967295){
        if (flag == 1){
          analogWrite(motorA1, 0);   analogWrite(motorA2, vSpeed); 
        analogWrite(motorB1, vSpeed);   analogWrite(motorB2, 0); flag = 0; delay(300);}
        
      }
      else{
          analogWrite(motorA1, vSpeed);   analogWrite(motorA2, 0); 
        analogWrite(motorB1, 0); analogWrite(motorB2, vSpeed);  flag = 1; delay(300);}
      
   irrecv.resume();
      
}
}
