#include <SoftwareSerial.h>

SoftwareSerial mySerial(11, 10); // RX, TX 
 int analogPin = 0;
 int val=0;
  
void setup()  
 { 
  // Open serial communication
  Serial.begin(9600);

  // set the data rate for the SoftwareSerial port
  mySerial.begin(9600);

  delay(1000);
  Serial.println("Testing SIM800L module");
  Serial.println();
  Serial.print("Sizeof(mySerial) = "); Serial.println(sizeof(mySerial));
  Serial.println();

}

void loop() // run over and over
{
  val = analogRead (analogPin);
  Serial.println (val);

  if(Serial.available())
  {
    String Arsp = Serial.readString();

    Serial.println("Serial available");
    Serial.println(Arsp);
    mySerial.println(Arsp);
    Serial.println("Serial available end");
  }

}
