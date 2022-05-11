#ifndef __CONFIG__
#define __CONFIG__

#define BTNUP_PIN 3
#define BTNDOWN_PIN 5
#define BTNMAKE_PIN 6
#define POT_PIN A0
#define TMP_PIN A3
#define SERVO_PIN 4
#define ECHO_PIN 7
#define TRIG_PIN 8
#define PIR_PIN 2

#define MAX_PRODUCT 40
#define MAX_TIME 10000
#define MAX_QTN_CHOCOLATE 50
#define MAX_QTN_TEA 50
#define MAX_QTN_COFFEE 50
#define T_CHECK 15 //seconds
#define T_TIMEOUT 5
#define DISTANCE 0.40 //meters
#define T_IDLE 60 //seconds
#define T_MAKING 10 //sec
#define T_BUTTON 5 //seconds

#define TEMPMIN 17 // Celsius degrees 
#define TEMPMAX 24 // Celsius degrees 

#define START_PERIOD 40
#define SELECT_PERIOD 40
#define MAKE_PERIOD 40
#define WITHDRAW_PERIOD 40
#define SELFTEST_PERIOD 100
#define COMMUNICATION_PERIOD 100


#endif
