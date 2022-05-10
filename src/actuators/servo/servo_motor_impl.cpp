#include "servo_motor_impl.h"
#include "Arduino.h"

ServoMotorImpl::ServoMotorImpl(int pin){
  this->pin = pin;  
  this->currentAnglePosition=0;
} 

void ServoMotorImpl::on(){
  motor.attach(pin);  
}

void ServoMotorImpl::setPosition(int angle){
	if (angle > 180){
		angle = 180;
	} else if (angle < 0){
		angle = 0;
	}
  float coeff = (2400.0-544.0)/180;
  motor.write(544 + angle*coeff);  
  currentAnglePosition=angle;            
}

void ServoMotorImpl::off(){
  motor.detach();    
}

int ServoMotorImpl::getAnglePosition(){
  return this->currentAnglePosition;
}
