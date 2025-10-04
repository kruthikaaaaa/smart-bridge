#include <Servo.h>

Servo tap_servo;

const int sensor_pin = 2;   // Try pin 2 for sensor
const int tap_servo_pin = 9; // Try pin 9 for servo (PWM)
int val;

void setup() {
  Serial.begin(9600);
  pinMode(sensor_pin, INPUT);
  tap_servo.attach(tap_servo_pin);
}

void loop() {
  val = digitalRead(sensor_pin);
  Serial.println(val);

  if (val == HIGH) {
    tap_servo.write(90); // Open tap
  } else {
    tap_servo.write(0);  // Close tap
  }
  delay(100);
}