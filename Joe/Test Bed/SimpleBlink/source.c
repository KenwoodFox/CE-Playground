#pragma config(Sensor, dgtl1,  limitSwitch,    sensorTouch)
#pragma config(Sensor, dgtl12, LEDOne,         sensorLEDtoVCC)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//


task main()
{
	while(true)
	{
		if(sensorValue(limitSwitch) == true)
		{
			turnLEDOn(LEDOne);
		}
		else
		{
			turnLEDOff(LEDOne);
		}
		delay(30);
	}
}
