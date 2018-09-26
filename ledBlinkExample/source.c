#pragma config(Sensor, dgtl1,  limitSwitch,    sensorTouch)
#pragma config(Sensor, dgtl2,  bumpSwitch,     sensorTouch)
#pragma config(Sensor, dgtl12, LEDOne,         sensorLEDtoVCC)
#pragma config(Motor,  port2,           starboardMotor, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           portMotor,     tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "toggleBlink.h" //Blink on/off command
#include "runMotors.h" //motor drive command

int operation = true;

task main()
{
	while(operation == true)
	{
		toggleBlink();
		runMotors();
	}
}
