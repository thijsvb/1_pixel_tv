//WARNING! the IRremote library will only work in an older version of the arduino IDE, I used 0023 you can find it here: http://arduino.cc/en/Main/OldSoftwareReleases 

#include <IRremote.h>
const int RECV_PIN = 6;
IRrecv irrecv(RECV_PIN);
decode_results results;        //recieving IR signals on pin 6 and decoding them

const int blue = 9;
const int red = 10;
const int green = 11;          //RGB led connections

const int standby = -1;
const int zero = 0;
const int one = 1;
const int two = 2;
const int three = 3;
const int four = 4;
const int five = 5;
const int six = 6;
const int seven = 7;
const int eight = 8;        //all the buttens and their decoded value, the numbers -1 to 10 are just placeholders
const int nine = 9;         //change these numbers to fit your remote, you can find the numbers in the serial monitor
const int hold = 10;        //this number appears when you hold a button so a button value will be recieved just once

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn();        // Start the receiver and serial monitor
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
}

void loop() {
  
  if (irrecv.decode(&results)) {
    Serial.println(results.value, DEC);  //print the decoded signal in the serial monitor
    irrecv.resume();                     // Receive the next value
  }
 const int remote = results.value;
 switch (remote) {
   
  case standby:
   analogWrite(green, 0);
   analogWrite(blue, 0);
   analogWrite(red, 0);
   break;
   
  case zero:
   analogWrite(green, 255);
   analogWrite(blue, 255);
   analogWrite(red, 255);
   break;
   
  case one:
   analogWrite(green, 0);
   analogWrite(blue, 0);
   analogWrite(red, 255);
   break;
   
  case two:
   analogWrite(green, 255);
   analogWrite(blue, 0);
   analogWrite(red, 0);
   break;
  
  case three:
   analogWrite(green, 0);
   analogWrite(blue, 255);
   analogWrite(red, 0);
   break;
  
  case four:
   analogWrite(green, 0);
   analogWrite(blue, 255);
   analogWrite(red, 255);
   break;
  
  case five:
   analogWrite(green, 255);
   analogWrite(blue, 0);
   analogWrite(red, 255);
   break;
  
  case six:
   analogWrite(green, 255);
   analogWrite(blue, 255);
   analogWrite(red, 0);
   break;                   
  
  case seven:
   analogWrite(green, 0);
   analogWrite(blue, 0);
   analogWrite(red, 0);
   break;
   
  case eight:
   analogWrite(green, 0);
   analogWrite(blue, 0);
   analogWrite(red, 0);
   delay(500);
   break;
   
  case nine:
   analogWrite(green, 0);
   analogWrite(blue, 0);
   analogWrite(red, 0);
   break;                   //change the colors to make this project your own   
                            //or maybe add a disco-mode, be creative!
  case hold:
   //don't do anything when you hold a button
   break;
 }
}
/*
Made by Thijs van Beers
Final version: 25-5-2014
*/

