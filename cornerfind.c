#ifndef _CORNER_
#define _CORNER_
void cornerfind()
{
	resetmotors();
	turnDegrees('s', halfgrid, motortarget, motortarget);
	resetmotors();
	while (nMotorEncoder[motorA] > closeclaw)
	{
		motor[motorA] = reversemotortarget;
	}
	resetmotors();
	turnDegrees('l', turntarget, reversemotortarget, motortarget);
	resetmotors();
	if (SensorValue[S4] < walldistance)
	{
		startturndirection = 'l';
		resetmotors();
		turnDegrees('r', turntarget, motortarget, reversemotortarget);
		resetmotors();
	}
	else
	{
		resetmotors();
		turnDegrees('r', turntarget, motortarget, reversemotortarget);
		resetmotors();
		turnDegrees('r', turntarget, motortarget, reversemotortarget);
		resetmotors();
		if (SensorValue[S4] < walldistance)
		{
			startturndirection = 'r';
			resetmotors();
			turnDegrees('l', turntarget, reversemotortarget, motortarget);
			resetmotors();
			startturndirection = 'r';
		}
		else
		{
			right = SensorValue[S4];
			resetmotors();
			turnDegrees('l', turntarget, reversemotortarget, motortarget);
			resetmotors();
			turnDegrees('l', turntarget, reversemotortarget, motortarget);
			resetmotors();
			left = SensorValue[S4];
			if (left > right)
			{
				resetmotors();
				turnDegrees('r', turntarget, motortarget, reversemotortarget);
				resetmotors();
				turnDegrees('r', turntarget, motortarget, reversemotortarget);
				resetmotors();
				while (SensorValue[S4] > walldistance)
				{
					motor[motorB] = motortarget;
					motor[motorC] = motortarget;
				}
				resetmotors();
				turnDegrees('l', turntarget, reversemotortarget, motortarget);
				resetmotors();
				startturndirection = 'r';
			}
			else
			{
				resetmotors();
				while (SensorValue[S4] > walldistance)
				{
					motor[motorB] = motortarget;
					motor[motorC] = motortarget;
				}
				resetmotors();
				turnDegrees('r', turntarget, motortarget, reversemotortarget);
				resetmotors();
				startturndirection = 'l';
			}
		}
	}
}
#endif
