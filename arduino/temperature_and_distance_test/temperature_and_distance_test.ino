#define trigPin 13
#define echoPin 12
#include <OneWire.h>
#include <DallasTemperature.h>
#define ONE_WIRE_BUS 9
#define TEMPERATURE_PRECISION 9
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  digitalWrite( 8 , LOW );
  pinMode( 8  , OUTPUT );
  digitalWrite( 10 , LOW );  
  pinMode( 10 , OUTPUT );
}

void loop() {
  int numberOfDevices; // Number of temperature devices found
  float tempC;

  DeviceAddress tempDeviceAddress; // We'll use this variable to store a found device address    
  
  // For testing purposes, reset the bus every loop so we can see if any devices appear or fall off
  sensors.begin();

  // Grab a count of devices on the wire
  numberOfDevices = sensors.getDeviceCount();

  sensors.requestTemperatures(); // Send the command to get temperatures
  
  // Loop through each device, print out temperature data
  for(int i=0;i<numberOfDevices; i++)
  {
    // Search the wire for address
    if(sensors.getAddress(tempDeviceAddress, i))
    {
      tempC = sensors.getTempC(tempDeviceAddress);
      Serial.print(tempC);
      Serial.print("\t");
    } 
  }
  long duration, distance;
  float speedofsound;
  speedofsound = 331.3+0.606*tempC;
  for(int i=0; i<10; i++){
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = 1.25*(duration*10/2)/speedofsound;
    if(distance<300){
      break;
    }
    else if(i=9){
      distance = -5;
      break;
    }
  }
  Serial.print(distance);
  Serial.print("\n");
  delay(500);
}

void printAddress(DeviceAddress deviceAddress)
{
  for (uint8_t i = 0; i < 8; i++)
  {
    if (deviceAddress[i] < 16) Serial.print("0");
    Serial.print(deviceAddress[i], HEX);
  }
}
