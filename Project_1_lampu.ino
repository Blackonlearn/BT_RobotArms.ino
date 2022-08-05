//Example 01: Blinking LED

#define LED 13 // LED Connected to 
               // digital pin 13

void setup()
{
  pinMode(LED,OUTPUT);
}

void loop()
{
  digitalWrite(LED,HIGH);
  delay(1000);
  digitalWrite(LED,LOW);
  delay(1000);
}
