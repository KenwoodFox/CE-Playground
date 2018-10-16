#pragma config(Motor,  port1,           starboardFore, tmotorVex393_HBridge, openLoop, reversed)
#pragma config(Motor,  port5,           portFore,      tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port6,           portAft,       tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port10,          starboardAft,  tmotorVex393_HBridge, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

//This function by Joe

void starboardDriveTrain(float speed) //function to drive each of the starboard wheels using value speed,
{
	int tune = 1; //tune adjust for the variablity of the wheels

	startMotor(starboardFore, speed * tune); //start both motors on this side running
	startMotor(starboardAft, speed * tune);
}

void portDriveTrain(float speed) //function to drive each of the port wheels using value speed,
{
	int tune = 1; //tune adjust for the variablity of the wheels

	startMotor(portFore, speed * tune); //start both motors on this side running
	startMotor(portAft, speed * tune);
}

//this function by joe, remeber to include my drivetrain.c before including this file

void easyGas(int targetSpeed, int accelValue, int accelDirection)
{
	int speed = 0; //arb value for the current speed

	while(speed < targetSpeed) //while you are not at target speed
	{
		speed = speed + accelDirection; //add 0.5 to the speed value
		delay(accelValue); //delay for this long
		starboardDriveTrain(speed); //set the speed
		portDriveTrain(speed);
	}
}

task main()
{
	easyGas(100, 5, 0.5); //accelerate at a rate of 0.5 every 5ms to 100 pwm
	delay(4000); //magic delay for the leangth of the
	easyGas(100, 5, -0.5);	//accelerate at a rate of -0.5 every 5ms to 100 pwm
}
