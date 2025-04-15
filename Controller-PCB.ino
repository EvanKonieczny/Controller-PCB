//#include <Mouse.h>

/*
  JoystickMouseControl

  Controls the mouse from a joystick on an Arduino Leonardo, Micro or Due.
  Uses a pushbutton to turn on and off mouse control, and a second pushbutton
  to click the left mouse button.

  Hardware:
  - 2-axis joystick connected to pins A0 and A1
  - pushbuttons connected to pin D2 and D3

  The mouse movement is always relative. This sketch reads two analog inputs
  that range from 0 to 1023 (or less on either end) and translates them into
  ranges of -6 to 6.
  The sketch assumes that the joystick resting values are around the middle of
  the range, but that they vary within a threshold.

  WARNING: When you use the Mouse.move() command, the Arduino takes over your
  mouse! Make sure you have control before you use the command. This sketch
  includes a pushbutton to toggle the mouse control state, so you can turn on
  and off mouse control.

  created 15 Sep 2011
  updated 28 Mar 2012
  by Tom Igoe

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/JoystickMouseControl
*/

//#include "Mouse.h"

// set pin numbers for switch, joystick axes, and LED:
const int switchPin = 2;    // switch to turn on and off mouse control
//const int mouseButton = 3;  // input pin for the mouse pushButton
const int xAxis = A0;       // joystick X axis
const int yAxis = A1;       // joystick Y axis
const int xAxis_2 = A2;       // joystick X axis
const int yAxis_2 = A3;       // joystick Y axis
const int ledPin = 5;       // Mouse control LED

const byte ENCODER_A = 0;
const byte ENCODER_B = 1;

// declare variables
int trigger_pin_1 = A6;
int trigger_pin_2 = A7;  // sensor pin
int trigger_1;  
int trigger_2;      // sensor readings
// LED pins
// parameters for reading the joystick:
//int range = 2;             // output range of X or Y movement
int responseDelay = 5;      // response delay of the mouse, in ms
// int threshold = range / 4;  // resting threshold
// int center = range / 2;     // resting position value

//bool mouseIsActive = false;  // whether or not to control the mouse
int lastSwitchState = LOW;   // previous switch state

volatile int16_t encoderPos = 0;

void setup() {
  pinMode(switchPin, INPUT);  // the switch pin
  pinMode(ledPin, OUTPUT);    // the LED pin

  pinMode(ENCODER_A, INPUT_PULLUP);
  pinMode(ENCODER_B, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(ENCODER_A), encoderISR, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ENCODER_B), encoderISR, CHANGE);

  // take control of the mouse:
  //Mouse.begin();
  Serial.begin(9600);

}

void loop() {
  // read the switch:
  // int switchState = digitalRead(switchPin);
  // // if it's changed and it's high, toggle the mouse state:
  // if (switchState != lastSwitchState) {
  //   if (switchState == HIGH) {
  //     mouseIsActive = !mouseIsActive;
  //     // turn on LED to indicate mouse state:
  //     digitalWrite(ledPin, mouseIsActive);
  //   }
  // }
  // save switch state for next comparison:
  // lastSwitchState = switchState;

  // read and scale the two axes:
  int xReading = readAxis(A0);
  int yReading = readAxis(A1);
  int xReading_2 = readAxis(A2);
  int yReading_2 = readAxis(A3);
  trigger_1 = analogRead(trigger_pin_1);
  trigger_2 = analogRead(trigger_pin_2);

    // print sensor value
  int trigger_1_level  = map(trigger_1, 1, 1000, 1, 10);     // 1 … 10
  int trigger_2_level  = map(trigger_2, 1, 1000, 1, 10);     // 1 … 10
  
  Serial.print(trigger_1_level);
  Serial.print(" ");
  Serial.print(trigger_2_level);
  Serial.print(" ");
  Serial.println(encoderPos);
  // if the mouse control state is active, move the mouse:
  // if (mouseIsActive) {
  //   Mouse.move(xReading, yReading, 0);
  // }

  // read the mouse button and click or not click:
  // if the mouse button is pressed:
    // if (digitalRead(mouseButton) == HIGH) {
    //   // if the mouse is not pressed, press it:
    //   if (!Mouse.isPressed(MOUSE_LEFT)) {
    //     Mouse.press(MOUSE_LEFT);
    //   }
    // }
    // // else the mouse button is not pressed:
    // else {
    //   // if the mouse is pressed, release it:
    //   if (Mouse.isPressed(MOUSE_LEFT)) {
    //     Mouse.release(MOUSE_LEFT);
    //   }
    // }

    delay(responseDelay);
  }

/*
  reads an axis (0 or 1 for x or y) and scales the analog input range to a range
  from 0 to <range>
*/

int readAxis(int thisAxis) {
  // read the analog input:
  int reading = analogRead(thisAxis);

  // map the reading from the analog input range to the output range:
  //reading = map(reading, 0, 1023, 0, range);

  // if the output reading is outside from the rest position threshold, use it:
  //int distance = reading - center;

  // if (abs(distance) < threshold) {
  //   distance = 0;
  // }

  // return the distance for this axis:
  Serial.print(reading);
  Serial.print(" ");
  return reading;
}

void encoderISR() {
  static byte lastState = 0;
  byte newState = (digitalRead(ENCODER_A) ? 2 : 0) + (digitalRead(ENCODER_B) ? 1 : 0);

  if ((lastState ^ newState) == 2) {
    encoderPos += (encoderPos & 1) ? -1 : 1;
  }
  else if ((lastState ^ newState) == 1) {
    encoderPos += (encoderPos & 1) ? 1 : -1;
  }
  lastState = newState;
}