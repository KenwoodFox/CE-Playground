#pragma config(Sensor, dgtl2,  bumpSwitch,     sensorTouch)
#pragma config(Motor,  port2,           starBoardFWD,  tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           starBoardBACK, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           portFWD,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           portBACK,      tmotorVex393_MC29, openLoop)
/*
Project Title: Tumbler Takes A Crappy Turn
Team Members: Grennon
Date: 10/13/2018
Section: Block C
Github: https://raw.githubusercontent.com/KenwoodFox/Joes-CE-Repo/master/Tumbler-takes-a-crappy-turn.c

Task Description:
My aim was just to make the tumbler bot turn left (port) 90 degrees sans Encoder

Pseudocode:
Code cycles continously (with while loop) until bump switch is pressed
Then moves forward for 11sec
Robot then attempts to turn left (Probably won't fully turn because I don't have any encoders so it's just a guess)
Robot takes a full stop and then goes forward at full speed for 5/6sec then stops and the contents of the If statement have been completed
While loop continues and waits for bump switch value to change from <bumpSwitch  == 0>
*/

void fullSpeedAhead()
{ // I'm much too lazy to write out four lines of code every time I want this damn robot to go forward 
	startMotor(starBoardBACK, 127);
	startMotor(starBoardFWD, 127);
	startMotor(portFWD, -127);
	startMotor(portBACK, -127);
}
void fullStop()
{ // I'm much too lazy to write out four lines of code every time I want this damn robot to stop 
	stopMotor(starBoardBACK);
	stopMotor(starBoardFWD);
	stopMotor(portFWD);
	stopMotor(portBACK);
}

task main()
{

	while(SensorValue[bumpSwitch] != true) //While the bump switch is not pressed
	{
		delay(10); //scanrate 10ms
	} //when this loop becomes untrue, it will advance to the rest of the code, no need for an infinate rpeating loop
	
	fullSpeedAhead(); //My function because I'm too lazy to type multiple "startMotor" statements

	delay(10000); /* Allows the bot to move forwards for 10sec but actually runs for 11sec
	because the second that the bump switch is pressed in is counted as well */

	pointTurn(left, 63); /* I have no clue how this'll turn because I don't have any encoders on
	to determine the cyclage count so this is just trial and error */

	delay(5000); /* Delays for 5sec to allow the robot to turn
	(Once again, I have no clue whether or not this is accurate this timing is only a placeholder) */

	fullStop(); //My lazy function (void)

	fullSpeedAhead(); // ^^

	delay(5000); //Robot runs for 5sec after its turn

	fullStop(); //Lazy function (void)
}
