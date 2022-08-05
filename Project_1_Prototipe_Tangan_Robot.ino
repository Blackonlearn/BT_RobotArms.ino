 #include <Servo.h> // menyertakan library servo ke dalam program 
 #include <Stepper.h> //menyertakan lisadbrary step motor ke dalam program
Servo myservo1; //variable untuk servo 1
Servo myservo2; //variable untuk servo 2
Servo myservo3; //variable untuk servo 3
Servo myservo4; //variable untuk servo 4
int pos = 90; //deklarasi variable pos dengan nilai awal 90 (digunakan untuk servo 1, sehingga nilai awal servo 1 adalah 90 yang berarti 90 derajat pada servo1)
int pos2 = 90; //deklarasi variable pos dengan nilai awal 90 (digunakan untuk servo 2, sehingga nilai awal servo 2 adalah 90 yang berarti 90 derajat pada servo2)
int pos3 = 90; //deklarasi variable pos dengan nilai awal 90 (digunakan untuk servo 3, sehingga nilai awal servo 3 adalah 90 yang berarti 90 derajat pada servo3)
int pos4 = 90; //deklarasi variable pos dengan nilai awal 90 (digunakan untuk servo 4, sehingga nilai awal servo 4 adalah 90 yang berarti 90 derajat pada servo4)

const float STEPS_PER_REV = 32; // deklarasi Revolusi Step motor
const float GEAR_RED = 64;  //Deklarasi Rotasi Stepmotor
const float STEPS_PER_OUT_REV = STEPS_PER_REV * GEAR_RED; //Deklarasi output stepmotor dengan nilai hasil kali dari revolusi dan rotasi
int StepsRequired;
Stepper steppermotor(STEPS_PER_REV, 8, 10, 9, 11); //deklarasi input yang dipakai oleh stepmotor

 void setup() {
Serial.begin(9600); //koneksi bluetooth
  myservo1.attach(4); //sinyal data kabel motor servo 1 dihubungkan di pin 4 Arduino
 myservo2.attach(5); //sinyal data kabel motor servo 2 dihubungkan di pin 5 Arduino
 myservo3.attach(6); //sinyal data kabel motor servo 3 dihubungkan di pin 6 Arduino
 myservo4.attach(7); //sinyal data kabel motor servo 4 dihubungkan di pin 7 Arduino
 pinMode(13, OUTPUT); // sintal data kabel LAMPU LED di hubungkan di pin 13
 }  

void loop() {
  // put your main code here, to run repeatedly:
 if(Serial.available()>0) //perulangan yang terjadi jika bluetooth terhubung
   {     
      char data= Serial.read(); // membaca data yang diterima dari modul bluetooth 
      switch(data)
      {
        //catatan : Servo 1 dan 2 di jadikan satu kondisi karena ada di posisi yang sama, yaitu posisi paling bawah setelah step motor (pangkal lengan tangan robot)

        
       case 'J': pos = pos + 3 ; //kondisi yang dijalankan jika data yang diterima bluetooth adalah "J"
                  pos2 = pos2 -3;
                  myservo1.write(pos2); //prosedur penulisan data PWM ke motor servo 1
                  myservo2.write(pos); //prosedur penulisan data PWM ke motor servo 2
                  delay(2); //waktu tunda 2 ms                
                  
                  break;
        case 'L': pos = pos - 3; //kondisi yang dijalankan jika data yang diterima bluetooth adalah "L"
                  pos2 = pos2 +3;
                  myservo1.write(pos2); //prosedur penulisan data PWM ke motor servo 1
                  myservo2.write(pos); //prosedur penulisan data PWM ke motor servo 2
                  delay(2); //waktu tunda 2 ms                
                  
                  break;
                  
        case 'K': pos = 90; //kondisi yang dijalankan jika data yang diterima bluetooth adalah "K" 
                  pos2 =90;
                  myservo1.write(pos); //prosedur penulisan data PWM ke motor servo 1
                  myservo2.write(pos); //prosedur penulisan data PWM ke motor servo 2
                  delay(100); //waktu tunda 100 ms
                  break;

        //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//          
        // Kondisi untuk Servo 3, bagian siku dari prototipe tangan robot
        
        case 'A': pos3 = pos3 + 3 ; //kondisi yang dijalankan jika data yang diterima bluetooth adalah "A"
                  myservo3.write(pos3); //prosedur penulisan data PWM ke motor servo
                  delay(2); //waktu tunda 2 ms                
                  
                  break;

                  
        case 'D': pos3 = pos3 - 3; //kondisi yang dijalankan jika data yang diterima bluetooth adalah "D"
                  myservo3.write(pos3);//prosedur penulisan data PWM ke motor servo
                  delay(2); //waktu tunda 2 ms                
                  
                  break;
                  
        case 'S': pos3 = 90; //kondisi yang dijalankan jika data yang diterima bluetooth adalah "S"
                  myservo3.write(pos3);//prosedur penulisan data PWM ke motor servo
                  delay(100); waktu tunda 100 ms
                  break;

        //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
        // Kondisi untuk Servo 4, bagian telapak dari prototipe tangan robot untuk menggerakkan capit

       case 'R': pos4 = pos4 + 3 ; //kondisi yang dijalankan jika data yang diterima bluetooth adalah "R"
                  pos4 <= 135;
                  myservo4.write(pos4); //prosedur penulisan data PWM ke motor servo
                  delay(2); //waktu tunda 2 ms                
                  
                  break;
        case 'T': pos4 = pos4 - 3; //kondisi yang dijalankan jika data yang diterima bluetooth adalah "T"
                  myservo4.write(pos4); //prosedur penulisan data PWM ke motor servo
                  delay(2); //waktu tunda 2 ms                
                  
                  break;
        case 'Y': pos4 = 90; //kondisi yang dijalankan jika data yang diterima bluetooth adalah "Y"
                  myservo4.write(pos4);//prosedur penulisan data PWM ke motor servo
                  delay(100); //waktu tunda 100 ms
                  break;
        
        case 'q': digitalWrite(13, HIGH);break; //kondisi yang dijalankan jika data yang diterima bluetooth adalah "q"
        case 'e': digitalWrite(13, LOW);break; //kondisi yang dijalankan jika data yang diterima bluetooth adalah "e"

        //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
        // Kondisi untuk Step Motor, bagian dasar tangan robot
        
        case 'z': StepsRequired  =  STEPS_PER_OUT_REV / 64; //kondisi yang dijalankan jika data yang diterima bluetooth adalah "z" / hasil output dibagi 64
        steppermotor.setSpeed(1000); //kecepatan stepmotor 1000
        steppermotor.step(StepsRequired); //Step motor menjalankan step sesuai dengan nilai yang diterima
        delay(10); break; //waktu tunda 10 ms

        case 'x': StepsRequired  =  -STEPS_PER_OUT_REV / 64; //kondisi yang dijalankan jika data yang diterima bluetooth adalah "z" / hasil negatif output dibagi 64
        steppermotor.setSpeed(1000);  //kecepatan stepmotor 1000
        steppermotor.step(StepsRequired); //Step motor menjalankan step sesuai dengan nilai yang diterima
        delay(10); break; //waktu tunda 10 ms
      }
      Serial.println(data);
   }
   delay(10);
}
