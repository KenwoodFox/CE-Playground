#pragma config(Sensor, in1,    lineFollower,   sensorLineFollower)
#pragma config(Sensor, in2,    pot,            sensorPotentiometer)
#pragma config(Sensor, in3,    lightSensor,    sensorReflection)
#pragma config(Sensor, dgtl1,  limitSwitch,    sensorTouch)
#pragma config(Sensor, dgtl2,  bumpSwitch,     sensorTouch)
#pragma config(Sensor, dgtl3,  encoderLower,   sensorNone)
#pragma config(Sensor, dgtl4,  encoderUpper,   sensorNone)
#pragma config(Sensor, dgtl5,  ultrasonicIn,   sensorNone)
#pragma config(Sensor, dgtl6,  ultrasonicOut,  sensorNone)
#pragma config(Sensor, dgtl12, LEDOne,         sensorLEDtoVCC)
#pragma config(Motor,  port1,           flashlight,    tmotorVexFlashlight, openLoop, reversed)
#pragma config(Motor,  port2,           starboardMotor, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           portMotor,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,            ,             tmotorServoStandard, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "myExampleHeader.h"

task main()
{
	myExampleVoid();
}
