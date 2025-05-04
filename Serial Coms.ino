int ledPin = 13;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("Enter a number:");
}

void loop() {
  if (Serial.available()) {
    int num = Serial.parseInt();
    Serial.println(num);

    if (num % 2 == 0) {
      Serial.println("Number is Even");
      blinkLED(3);  // Now 3 times for even
    } else {
      Serial.println("Number is Odd");
      blinkLED(2);  // Now 2 times for odd
    }
  }
}

void blinkLED(int times) {
  for (int i = 0; i < times; i++) {
    digitalWrite(ledPin, HIGH);
    delay(300);
    digitalWrite(ledPin, LOW);
    delay(300);
  }
}
--------------------------------------------------------------------------
#include <Servo.h>

int servoPin = 3;
Servo servo;
int num = 0; // Declare num globally

void setup() {
  servo.attach(servoPin);
  Serial.begin(9600);
  Serial.println("Enter a number:");
}

void loop() {
  if (Serial.available()) {
    num = Serial.parseInt(); // Update the global variable
    Serial.print("You Entered: ");
    Serial.println(num);

    if (num < 40) {
      servo.write(90);
    } else {
      servo.write(180);
    }

    delay(500); // Give time for servo to move
    Serial.println("Enter another number:");
  }
}

