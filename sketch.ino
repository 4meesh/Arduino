#include <Servo.h>

// Servo motor setup
const int servoPin = 9; 
int ledPin=11;
int IR=3;// Orange wire to pin 9
Servo servo;

// Ultrasonic sensor setup
const int trigPin = 6;  // Trigger pin connected to pin 6
const int echoPin = 7;  // Echo pin connected to pin 7

long duration;
int distance;
void setup() {
  pinMode(IR, INPUT);
  pinMode(ledPin, OUTPUT);
  servo.attach(servoPin);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Start serial monitor
  Serial.begin(9600);
  // put your setup code here, to run once:
}

void loop() {
  // Ultrasonic distance measurement
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

duration = pulseIn(echoPin, HIGH);
distance = duration * 0.034 / 2;

Serial.print("Distance: ");
Serial.println(distance);

  int sensorVal;
  sensorVal=digitalRead(IR);
  Serial.println(sensorVal);
  if (sensorVal==0){
    digitalWrite(ledPin, HIGH);
    servo.write(90);
  }
  else{
   digitalWrite(ledPin, LOW);
   servo.write(0);
  }
  // put your main code here, to run repeatedly:

}
