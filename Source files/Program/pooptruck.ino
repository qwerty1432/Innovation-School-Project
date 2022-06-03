#include <Servo.h>

Servo linear_servo;
Servo rotational_servo;
Servo door_servo;

int pos_up = 120;
int pos_down = 50;
int pos_forward = 180;
int pos_backward = 0;
int pos_open = 180;
int pos_close = 0;

//int init_pos_linear= 180;
//int init_pos_rotational = 120;

void setup() {
  linear_servo.attach(9);
  rotational_servo.attach(10);
  linear_servo.write(pos_backward);
  rotational_servo.write(pos_up);
  door_servo.attach(11);
  door_servo.write(pos_close);
  Serial.begin(9600);
}

void loop() {
  Open();
  forward();
  down();
  backward();
  up();
  Close();
  delay(2000);

}

void backward() {
  for (int i = pos_backward; i <= pos_forward; i++) {
    linear_servo.write(i);
    delay(20);
    Serial.print("forward ");
    Serial.println(i);
  }
}

void forward() {
  for (int i = pos_forward; i >= pos_backward; i--) {
    linear_servo.write(i);
    delay(20);
    Serial.print("backward ");
    Serial.println(i);
  }
}

void down() {
  for (int i = pos_up; i >= pos_down; i--) {
    rotational_servo.write(i);
    delay(20);
    Serial.print("down ");
    Serial.println(i);
  }
}

void up() {
  for (int i = pos_down; i <= pos_up; i++) {
    rotational_servo.write(i);
    delay(20);
    Serial.print("up ");
    Serial.println(i);
  }
}

void Close() {
  for (int i = pos_close; i <= pos_open; i++) {
    door_servo.write(i);
    delay(20);
    Serial.print("open ");
    Serial.println(i);
  }
}

void Open() {
  for (int i = pos_open; i >= pos_close; i--) {
    door_servo.write(i);
    delay(20);
    Serial.print("close ");
    Serial.println(i);
  }
}
