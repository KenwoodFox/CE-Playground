void tankSpin(float targetRotation)
{
	int tune = 1050; ///change me!
	int robotSpeed = 40;


	if(targetRotation == -90)
	{
		starboardDriveTrain(robotSpeed);
		portDriveTrain((robotSpeed * -1));
		delay(tune);
	}
	if(targetRotation == 90)
	{
		starboardDriveTrain((robotSpeed * -1));
		portDriveTrain(robotSpeed);
		delay(tune);
	}
	starboardDriveTrain(0);
	portDriveTrain(0);


	//stop all moitotrsz
}
