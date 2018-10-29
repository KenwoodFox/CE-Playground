#pragma config(Sensor, in6,    portReflector,  sensorLineFollower)
#pragma config(Sensor, in7,    masterReflector, sensorLineFollower)
#pragma config(Sensor, in8,    starboardReflector, sensorLineFollower)
#pragma config(Sensor, dgtl1,  LED,            sensorLEDtoVCC)
#pragma config(Sensor, dgtl10, bowSwitch,      sensorTouch)
#pragma config(Sensor, dgtl11, sternSwitch,    sensorTouch)
#pragma config(Sensor, dgtl12, bumpSwitch,     sensorTouch)
#pragma config(Motor,  port1,           starboardAft,  tmotorVex393_HBridge, openLoop, reversed)
#pragma config(Motor,  port8,           starboardFore, tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           portAft,       tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port10,          portFore,      tmotorServoContinuousRotation, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "drivetrain.h" //include the drivetrain header
#include "init.h" //Include init.h, init.h also includes void startup();
#include "tankSpin.h"
#include "blink.h" //blink header, for easy blonks

#include "lineFollowing.c" //the line folowing library team 3 made!

task main()
{
	while(true)
	{
		startup(bumpSwitch, LED);
		findLine(); //our first task is to find where the line is, duh, so we can follow it!
		linePID();

	}
}
