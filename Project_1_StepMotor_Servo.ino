/*
  Stepper Motor Demonstration 1
  Stepper-Demo1.ino
  Demonstrates 28BYJ-48 Unipolar Stepper with ULN2003 Driver
  Uses Arduino Stepper Library
 
  DroneBot Workshop 2018
  https://dronebotworkshop.com
*/
 
//Include the Arduino Stepper Library
#include <Stepper.h>
#define LED 13
#include <Servo.h> // menyertakan library servo ke dalam program 
Servo myservo1;
Servo myservo2;
Servo myservo3;
Servo myservo4;// variable untuk menyimpan posisi data
int pos1 = 00;
int pos2 = 00;
 
// Define Constants
 
// Number of steps per internal motor revolution 
const float STEPS_PER_REV = 32; 
 
//  Amount of Gear Reduction
const float GEAR_RED = 64;
 
// Number of steps per geared output rotation
const float STEPS_PER_OUT_REV = STEPS_PER_REV * GEAR_RED;
 
// Define Variables
 
// Number of Steps Required
int StepsRequired;
 
// Create Instance of Stepper Class
// Specify Pins used for motor coils
// The pins used are 8,9,10,11 
// Connected to ULN2003 Motor Driver In1, In2, In3, In4 
// Pins entered in sequence 1-3-2-4 for proper step sequencing
 
Stepper steppermotor(STEPS_PER_REV, 8, 10, 9, 11);
 
void setup()
{
  pinMode(LED, OUTPUT);
// Nothing  (Stepper Library sets pins as outputs)
 myservo1.attach(4); //sinyal data kabel motor servo dikonekan di pin 3 Arduino
 myservo2.attach(5);
 myservo3.attach(6);
 myservo4.attach(7);
}
 
void loop()
{
  // Slow - 4-step CW sequence to observe lights on driver board
  /*steppermotor.setSpeed(1);    
  StepsRequired  =  1;
  steppermotor.step(StepsRequired);
  delay(500);
  */

                  for(pos1 = 00; pos1 < 75; pos1 += 1)  //semakin naik nilainya, putar counter clockwise | fungsi perulangan yang akan dijadikan PWM dengan kenaikan 1
                 {
                  myservo3.write(pos1);//prosedur penulisan data PWM ke motor servo
                  delay(30); //waktu tunda 15 ms                 
                 } 
              
                  delay(1000);
                  
                  for(pos2 = 45; pos2 >= 00 ; pos2 -= 1)  //semakin turun nilainya, putar counterclockwise | fungsi perulangan yang akan dijadikan PWM dengan kenaikan 1
                   {
                    myservo2.write(pos2);//prosedur penulisan data PWM ke motor servo
                    delay(30); //waktu tunda 15 ms                 
                   }
                  
                  delay(1000);
                  
                  for(pos2 = 00; pos2 < 45; pos2 += 1)  //semakin naik nilainya, putar clockwise | fungsi perulangan yang akan dijadikan PWM dengan kenaikan 1
                   {
                    myservo2.write(pos2);//prosedur penulisan data PWM ke motor servo
                    delay(30); //waktu tunda 15 ms                 
                   }
                  
                  delay(1000);
                   
                   for(pos1 = 75; pos1 > 00; pos1 -= 1)  //semakin naik nilainya, putar counter clockwise | fungsi perulangan yang akan dijadikan PWM dengan kenaikan 1
                   {
                    myservo3.write(pos1);//prosedur penulisan data PWM ke motor servo
                    delay(30); //waktu tunda 15 ms                 
                   } 
                  
                  delay(1000);

                   // Rotate CW 1/2 turn slowly
  StepsRequired  =  STEPS_PER_OUT_REV / 4; // kalo plus, counter Clockwise
  steppermotor.setSpeed(1000);   
  steppermotor.step(StepsRequired);
  delay(1000);

  
  // Rotate CCW 1/2 turn quickly
  StepsRequired  =  - STEPS_PER_OUT_REV / 4;   // kalo min, Clockwise
  steppermotor.setSpeed( 1000);  
  steppermotor.step(StepsRequired);
  delay(1000);

}
