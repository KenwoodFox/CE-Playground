#pragma config(Sensor, dgtl1,  limitSwitch,    sensorTouch)
#pragma config(Sensor, dgtl2,  bumpSwitch,     sensorTouch)
#pragma config(Sensor, dgtl12, LEDOne,         sensorLEDtoVCC)
#pragma config(Motor,  port2,           starboardMotor, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           portMotor,     tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "flash.c" //Include the blink task, that allows us to run a blink thread
#include "motorInit.c" //motorInit.c contains a motor init void,

task driveTask() //Tasks need to be defined before the task main, as they will compile in order
{
	int trip = false; //this trip value determines if the limit switch has been triggered, if true, the motor reverse drive will not run, this allows us to shut on and off the motors in a situation other than just the limit switch

	startMotor(starboardMotor, -80); //these two commands start the motors moving in reverse
	startMotor(portMotor, -80);

	while(trip == false) //for as long as we are not tripped off...
	{
		if(SensorValue(limitSwitch) == 1) //...but if the limit switch is not pressed right now
		{
			trip = true; //trip the motors off
			delay(20);
		}
		else //otherwise
		{
			delay(20); //dont trip the motors off
		}
	}
	stopMotor(starboardMotor);
	stopMotor(portMotor); //stop motors

	stopTask(driveTask); //stop the drivetask daemen, this will keep the motors from restarting
}

task main()
{
	startTask(blink, 5); //begin the blinking daemen
	motorInit(); //init the motors with the startup sequence
	startTask(driveTask, 10); //begin the drivetask daemen
	while(true) //do forever...
	{
		delay(2000); //alotocate all CPUT time for tasks
	}
}
