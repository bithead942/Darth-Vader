/*********************************************
Darth Vader Magic 8 Ball
by Bithead942

When the button (head) is pressed, a random number is generated and the audio associated 
with that number is played asynchronously.  Also, each of the 3 servos are moved to the 
pre-selected posistions for the given response while the audio is being played.

The servos are attached and detached each time in order to stop the servos from chattering.

Digital Pins
2 - WTV020SD reset
3 - WTV020SD clock
4 - WTV020SD data
5 - WTV020SD busy
6 - button pin - activates response
9 - Left Arm Servo
10 - Right Arm Servo
11 - Leg Servo


*************************************************/

#include <Wtv020sd16p.h>
#include <Servo.h>

const int resetPin = 2;
const int clockPin = 3;
const int dataPin = 4;
const int busyPin = 5;
const int buttonPin = 6;
const int LArmPin = 9;
const int RArmPin = 10;
const int LegPin = 11;

Wtv020sd16p SoundModule(resetPin, clockPin, dataPin, busyPin);
Servo LArmServo;  // create servo object to control a servo
Servo RArmServo;  // create servo object to control a servo
Servo LegServo;  // create servo object to control a servo

void setup() {
  SoundModule.reset();
  SoundModule.unmute();
  //Serial.begin(9600);

  pinMode(buttonPin, INPUT);
  LArmServo.attach(LArmPin);
  RArmServo.attach(RArmPin);
  LegServo.attach(LegPin);
  Start_Position();  
  delay(500);
  LArmServo.detach();
  RArmServo.detach();
  LegServo.detach();
  SoundModule.asyncPlayVoice(0);   //Startup Sound
  delay(3500);
  randomSeed(analogRead(0));
  //Serial.println("Ready");
}

void loop() {
byte iPlayVal = 0;

  if (digitalRead(buttonPin) == HIGH)
  {
    iPlayVal = random(1, 16);  // results in a random number from 1 to 15
    SoundModule.asyncPlayVoice(iPlayVal);
    //Serial.println(iPlayVal);

    LArmServo.attach(LArmPin);
    RArmServo.attach(RArmPin);
    LegServo.attach(LegPin);
  
    switch (iPlayVal) {
      case 1:  //As you wish
        LArmServo.write(45);
        RArmServo.write(45);
        LegServo.write(90);
        break;

      case 2:  //Yes, my master
        LArmServo.write(0);
        RArmServo.write(0);
        LegServo.write(90);
        break;

      case 3:  //That is correct
        LArmServo.write(0);
        RArmServo.write(90);
        LegServo.write(90);
        break;

      case 4:  //Search your feelings
        LArmServo.write(0);
        RArmServo.write(0);
        LegServo.write(90);
        break;

      case 5:  //Yes, Admiral
        LArmServo.write(45);
        RArmServo.write(0);
        LegServo.write(90);
        break;

      case 6:  //Breathing
        LArmServo.write(60);
        RArmServo.write(60);
        LegServo.write(0);
        break;

      case 7:  //You don't know the power
        LArmServo.write(30);
        RArmServo.write(0);
        LegServo.write(90);
        break;

      case 8:  //Tie Fighter
        LArmServo.write(0);
        RArmServo.write(30);
        LegServo.write(0);
        break;

      case 9:  //Imperial March
        LArmServo.write(0);
        RArmServo.write(0);
        LegServo.write(90);
        break;

      case 10:  //Light Saber
        LArmServo.write(45);
        RArmServo.write(0);
        LegServo.write(0);
        break;

      case 11:  //The Emperor does not share...
        LArmServo.write(45);
        RArmServo.write(45);
        LegServo.write(0);
        break;

      case 12:  //It is pointless to resist
        LArmServo.write(90);
        RArmServo.write(30);
        LegServo.write(0);
        break;

      case 13:  //Nooooo
        LArmServo.write(90);
        RArmServo.write(45);
        LegServo.write(0);
        break;

      case 14:  //Don't fail me again
        LArmServo.write(0);
        RArmServo.write(0);
        LegServo.write(0);
        break;

      case 15:  //You have failed me for the last time
        LArmServo.write(30);
        RArmServo.write(0);
        LegServo.write(0);
        break;
    }
    delay(1000);
    Start_Position();
    delay(500);
    LArmServo.detach();
    RArmServo.detach();
    LegServo.detach();
  }
}

void Start_Position() {                                  
    LArmServo.write(0);
    RArmServo.write(90);
    LegServo.write(0);                                    
}
