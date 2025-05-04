#include <Servo.h>

// Servo motor setup
const int servoPin = 9; // Orange wire to pin 9
Servo servo;

// Ultrasonic sensor setup
const int trigPin = 6;  // Trigger pin connected to pin 6
const int echoPin = 7;  // Echo pin connected to pin 7

long duration;
int distance;

void setup() {
  // Setup for servo motor
  servo.attach(servoPin);

  // Setup for ultrasonic sensor
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Start serial monitor
  Serial.begin(9600);
}

void loop() {
  // Ultrasonic sensor: send pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read echo pulse
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // If vehicle is within 10 cm, open gate
  if (distance < 10) {
    servo.write(90); // open gate
    delay(3000);     // wait for 3 seconds
    servo.write(0);  // close gate
  } else {
    servo.write(0);  // keep gate closed
  }

  delay(500); // slight delay before next reading
}
