/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Blink
*/
int col1=2;
int row1=A0;
int row2=A1;
int row3=A2;
int row4=A3;
int row5=A4;
int row6=A5;
int row7=A6;
int row8=A7;

int motor=A8;


// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(col1, OUTPUT);
  pinMode(row1, OUTPUT);
  pinMode(row2, OUTPUT);
  pinMode(row3, OUTPUT);
  pinMode(row4, OUTPUT);
  pinMode(row5, OUTPUT);
  pinMode(row6, OUTPUT);
  pinMode(row7, OUTPUT);
  pinMode(row8, OUTPUT);
  pinMode(motor, OUTPUT);
    
  digitalWrite(col1,LOW);
  analogWrite(row1,0);
  analogWrite(row2,0);
  analogWrite(row3,0);
  analogWrite(row4,0);
  analogWrite(row5,0);
  analogWrite(row6,0);
  analogWrite(row7,0);
  analogWrite(row8,0);
  analogWrite(motor,0);
}

// the loop function runs over and over again forever
void loop() {

  analogWrite(motor,100);
  
  analogWrite(row1, 160);   // turn the LED on (HIGH is the voltage level)
  delay(1);                       // wait for a second
  analogWrite(row1, 0);    // turn the LED off by making the voltage LOW
  delay(2);                       // wait for a second
  
  analogWrite(row2, 150);   
  delay(1);                
  analogWrite(row2, 0);    
  delay(2); 

  analogWrite(row3, 140);   
  delay(1);                
  analogWrite(row3, 0);    
  delay(2);

  analogWrite(row4, 130);   
  delay(1);                
  analogWrite(row4, 0);    
  delay(2);

  analogWrite(row5, 130);   
  delay(1);                
  analogWrite(row5, 0);    
  delay(2);

  analogWrite(row6, 130);   
  delay(1);                
  analogWrite(row6, 0);    
  delay(2);

  analogWrite(row7, 130);   
  delay(1);                
  analogWrite(row7, 0);    
  delay(2);

  analogWrite(row8, 130);   
  delay(1);                
  analogWrite(row8, 0);    
  delay(2);
}
