#include <Servo.h>

Servo xServo;
Servo yServo;

#DEFINE SERVOX_PIN 26;
#DEFINE SERVOY_PIN 27;
#DEFINE MAX_DISTANCE_CM 100.0

void setup() {
  Serial.begin(115200);

  xServo.attach(SERVOX_PIN); 
  yServo.attach(SERVOY_PIN); 

  int triggerPin = 2;
  int echoPin = 3;
  int button = 14;

  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(button,INPUT_PULLUP);
}

void loop() {
  if(digitalRead(button,LOW)){
    Scan();
  }

  

}



double readDistance(int triggerPin, int echoPin) {
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  long duration = pulseIn(echoPin, HIGH);
  double distanceCM = (duration / 2.0) * 0.0343;
  double normalizedDistance = constrain(distanceCM / MAX_DISTANCE_CM, 0.0, 1.0);
  return normalizedDistance;
}




void Scan(){
  //this is supposed to be a raster scan
  yServo.write(0);
  xServo.write(0);
  for (int xDeg = 0; xDeg <= 180; xDeg++) {
    
    xServo.write(xDeg);
    Serial.println("\n");

    
    for (int yDeg = 0; yDeg <= 120; yDeg++) {
      yServo.write(yDeg);
      Serial.print(readDistance());
      
    }
    yServo.write(0);
  }
}