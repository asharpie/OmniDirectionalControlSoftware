#include <AFMotor.h>
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

void setup() 
{
  Serial.begin(9600);
	//Set initial speed of the motor & stop
	motor1.setSpeed(200);
	motor1.run(RELEASE);
  motor2.setSpeed(200);
	motor2.run(RELEASE);
  motor3.setSpeed(200);
	motor3.run(RELEASE);
  motor4.setSpeed(200);
	motor4.run(RELEASE);
}

void loop() 
{
	drive(255,0,10000);
}
void drive(int speed,int degree,double time){
  double angleRad = radians(degree);
  motor1.setSpeed(abs(speed * cos(angleRad + PI / 4)));
  motor2.setSpeed(abs(speed * sin(angleRad + PI / 4)));
  motor3.setSpeed(abs(speed * cos(angleRad + PI / 4)));
  motor4.setSpeed(abs(speed * sin(angleRad + PI / 4)));
  if(abs(speed * cos(angleRad + PI / 4))>0){
    motor1.run(FORWARD);
    motor3.run(FORWARD);
  }
  else{
    motor1.run(BACKWARD);
    motor3.run(BACKWARD);
  }
  if(abs(speed * sin(angleRad + PI / 4))>0){
    motor2.run(FORWARD);
    motor4.run(FORWARD);
  }
  else{
    motor2.run(BACKWARD);
    motor4.run(BACKWARD);
  }
  delay(time);
}
void pivotLeft(double time){ //can use degree variable later after testing and or directional sensors are added
//pivots around center of robot
  motor1.setSpeed(255);
  motor2.setSpeed(255);
  motor3.setSpeed(255);
  motor4.setSpeed(255);
  motor1.run(BACKWARD);
  motor4.run(BACKWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  delay(time);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}
void pivotRight(double time){ //can use degree variable later after testing and or directional sensors are added
//pivots around center of robot
  motor1.setSpeed(255);
  motor2.setSpeed(255);
  motor3.setSpeed(255);
  motor4.setSpeed(255);
  motor1.run(FORWARD);
  motor4.run(FORWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  delay(time);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}
  