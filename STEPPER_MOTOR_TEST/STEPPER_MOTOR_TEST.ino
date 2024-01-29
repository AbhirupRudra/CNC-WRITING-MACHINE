# include <AccelStepper.h>

int dirpin = 2;
int steppin = 3;

#define motorinterfacetype 1

AccelStepper mystepper(motorinterfacetype, steppin, dirpin);

void setup(){
  mystepper.setMaxSpeed(1000);
  mystepper.setAcceleration(50);
  mystepper.setSpeed(400);
  mystepper.moveTo(200); 
}

void loop(){
  if(mystepper.distanceToGo() == 0){
    mystepper.moveTo(-mystepper.currentPosition());
  }

  mystepper.run();
}