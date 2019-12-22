#include <AccelStepper.h>
AccelStepper stepper(8, 8, 10, 9, 11);

void setup()
{
  stepper.setMaxSpeed(1000.0);
  stepper.setAcceleration(100.0);
  //stepper.setSpeed(850);
  //stepper.moveTo(8*360);
   
}


void loop()
{
//  int i = 1;
//  while(true) {
//    stepper.moveTo(8*360*i);
//    stepper.run();
//    i++;
//  }
  stepper.runToNewPosition(0);
  delay(5000);
  stepper.runToNewPosition(64*32*3);
  delay(5000);
  stepper.runToNewPosition(64*32*2);
  delay(5000);
  stepper.runToNewPosition(64*32);
  delay(5000);
}
