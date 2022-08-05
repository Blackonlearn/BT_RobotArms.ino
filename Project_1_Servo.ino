#include <Servo.h> // menyertakan library servo ke dalam program 
Servo myservo1;
Servo myservo2;
Servo myservo3;
Servo myservo4;// variable untuk menyimpan posisi data
int pos1 = 00;
int pos2 = 00;   
         
void setup(){ 
 myservo1.attach(4); //sinyal data kabel motor servo dikonekan di pin 3 Arduino
 myservo2.attach(5);
 myservo3.attach(6);
 myservo4.attach(7);
} 
 
void loop(){
  for(pos1 = 00; pos1 < 90; pos1 += 1)  //semakin naik nilainya, putar counter clockwise | fungsi perulangan yang akan dijadikan PWM dengan kenaikan 1
 {
  myservo3.write(pos1);//prosedur penulisan data PWM ke motor servo
  delay(10); //waktu tunda 15 ms                 
 } 

delay(1000);

 for(pos1 = 90; pos1 > 00; pos1 -= 1)  //semakin naik nilainya, putar counter clockwise | fungsi perulangan yang akan dijadikan PWM dengan kenaikan 1
 {
  myservo3.write(pos1);//prosedur penulisan data PWM ke motor servo
  delay(10); //waktu tunda 15 ms                 
 } 

delay(1000);
}
