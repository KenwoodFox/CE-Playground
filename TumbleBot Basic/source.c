#pragma config(Sensor, dgtl1,  bumpSwitch,     sensorTouch)
#pragma config(Motor,  port1,           starboardFore, tmotorVex393_HBridge, openLoop, reversed)
#pragma config(Motor,  port5,           portFore,      tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port6,           portAft,       tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port10,          starboardAft,  tmotorVex393_HBridge, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "drivetrain.h" //include the drivetrain header
#include "easyGas.h" //include the easygas header

task main()
{
	while(bumpSwitch != true) //while bumpswitch is not pressed
	{
		delay(10); //wait 10ms
	}

	delay(900); //after pressing the bump switch, wait 900ms before starting the program

	easyGas(100, 5, 0.5); //accelerate at a rate of 0.5 every 5ms to 100 pwm
	delay(4000); //magic delay for the leangth of the
	easyGas(100, 5, -0.5);	//accelerate at a rate of -0.5 every 5ms to 100 pwm
}
