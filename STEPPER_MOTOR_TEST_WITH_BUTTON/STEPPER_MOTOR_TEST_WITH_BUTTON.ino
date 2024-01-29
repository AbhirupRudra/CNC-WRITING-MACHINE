#include <AccelStepper.h>
#include <Button.h>

int dirpin = 2;
int steppin = 3;
int buttonpinA = 5;
int buttonpinB = 6;

int speed = 400;


#define motorinterfacetype 1

Button buttonA = Button(buttonpinA, BUTTON_PULLUP);
Button buttonB = Button(buttonpinB, BUTTON_PULLUP);

AccelStepper mystepper(motorinterfacetype, steppin, dirpin);

void setup(){
//  pinMode(potpin, INPUT);

  mystepper.setMaxSpeed(1000);
  mystepper.setAcceleration(50);
  mystepper.setSpeed(speed);
}

void loop(){

  if(buttonA.isPressed()){
    mystepper.move(200);
  }

  if(buttonB.isPressed()){
    mystepper.move(-200);
  }

  mystepper.run();
}