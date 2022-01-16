#ifndef _GREEN_
#define _GREEN_
void greensquare()
{
	if (l == 1 && r == 1)
	{
		resetmotors();
		turnDegrees('s', straighttarget, motortarget, motortarget);
		resetmotors();
		sensorvalues();
		if (xvalue < sensoraverage && avalue < sensoraverage)
		{
			resetmotors();
			turnDegrees('s', 2 * straighttarget, motortarget, motortarget);
			resetmotors();
			turnDegrees('r', doubletarget, motortarget, reversemotortarget);
			resetmotors();
			sensorvalues();
			while (avalue > sensoraverage)
			{
				motor[motorB] = motortarget;
				motor[motorC] = reversemotortarget;
				sensorvalues();
			}
			resetmotors();
			sensorvalues();
			nogreenset();
		}
		else
		{
			resetmotors();
			sensorvalues();
			if (xvalue > sensoraverage && avalue > sensoraverage)
			{
				resetmotors();
				turnDegrees('s', encodersetpoint - doublestraight * straighttarget, reversemotortarget, reversemotortarget);
				resetmotors();
				sensorvalues();
				nogreenset();
			}
			else
			{
				resetmotors();
				sensorvalues();
				nogreenset();
			}
		}
	}
	else if (l == 1 && r == 0)
	{
		resetmotors();
		while(nMotorEncoder[motorC] < 360/(wheeldiameter * PI) * doublegreenstraighttarget)
		{
			motor[motorB] = 0;
			motor[motorC] = motortarget;
		}
		resetmotors();
		sensorvalues();
		findgreen();
		resetmotors();
		while(nMotorEncoder[motorB] < 360/(wheeldiameter * PI) * doublegreenstraighttarget)
		{
			motor[motorB] = motortarget;
			motor[motorC] = 0;
		}
		resetmotors();
		if (r == 1)
		{
			resetmotors();
			turnDegrees('s', greenstraighttarget, motortarget, motortarget);
			resetmotors();
			sensorvalues();
			if (xvalue < sensoraverage && avalue < sensoraverage)
			{
				resetmotors();
				turnDegrees('s', 2 * straighttarget, motortarget, motortarget);
				resetmotors();
				turnDegrees('r', doubletarget, motortarget, reversemotortarget);
				resetmotors();
				sensorvalues();
				while (avalue > sensoraverage)
				{
					motor[motorB] = motortarget;
					motor[motorC] = reversemotortarget;
					sensorvalues();
				}
				resetmotors();
				sensorvalues();
				nogreenset();
			}
			else
			{
				resetmotors();
				sensorvalues();
				if (xvalue > sensoraverage && avalue > sensoraverage)
				{
					resetmotors();
					turnDegrees('s', encodersetpoint - doublestraight * straighttarget, reversemotortarget, reversemotortarget);
					resetmotors();
					sensorvalues();
					nogreenset();
				}
				else
				{
					sensorvalues();
					nogreenset();
				}
			}
		}
		else
		{
			resetmotors();
			turnDegrees('s', straighttarget, motortarget, motortarget);
			resetmotors();
			sensorvalues();
			if (xvalue < sensoraverage)
			{
				resetmotors();
				turnDegrees('s', straighttarget, motortarget, motortarget);
				resetmotors();
				turnDegrees('l', singletarget, greenturn, motortarget);
				resetmotors();
				sensorvalues();
				while (avalue > sensoraverage)
				{
					motor[motorB] = greenturn;
					motor[motorC] = motortarget;
					sensorvalues();
				}
				resetmotors();
				sensorvalues();
				nogreenset();
			}
			else
			{
				resetmotors();
				sensorvalues();
				if (xvalue > sensoraverage && avalue > sensoraverage)
				{
					resetmotors();
					turnDegrees('s', encodersetpoint - doublestraight * straighttarget, reversemotortarget, reversemotortarget);
					resetmotors();
					sensorvalues();
					while(avalue > turnlimit)
					{
						sensorvalues();
						motor[motorB] = nosquare;
						motor[motorC] = motortarget;
					}
					resetmotors();
					turnDegrees('s', straighttarget, motortarget, motortarget);
					resetmotors();
					sensorvalues();
					nogreenset();
				}
				else
				{
					sensorvalues();
					nogreenset();
				}
			}
		}
	}
	else if (l == 0 && r == 1)
	{
		resetmotors();
		while(nMotorEncoder[motorB] < 360/(wheeldiameter * PI) * doublegreenstraighttarget)
		{
			motor[motorB] = motortarget;
			motor[motorC] = 0;
		}
		resetmotors();
		sensorvalues();
		findgreen();
		resetmotors();
		while(nMotorEncoder[motorC] < 360/(wheeldiameter * PI) * doublegreenstraighttarget)
		{
			motor[motorB] = 0;
			motor[motorC] = motortarget;
		}
		resetmotors();
		if (l == 1)
		{
			resetmotors();
			turnDegrees('s', greenstraighttarget, motortarget, motortarget);
			resetmotors();
			sensorvalues();
			if (xvalue < sensoraverage && avalue < sensoraverage)
			{
				resetmotors();
				turnDegrees('s', 2 * straighttarget, motortarget, motortarget);
				resetmotors();
				turnDegrees('r', doubletarget, motortarget, reversemotortarget);
				resetmotors();
				sensorvalues();
				while (avalue > sensoraverage)
				{
					motor[motorB] = motortarget;
					motor[motorC] = reversemotortarget;
					sensorvalues();
				}
				resetmotors();
				sensorvalues();
				nogreenset();
			}
			else
			{
				resetmotors();
				sensorvalues();
				if (xvalue > sensoraverage && avalue > sensoraverage)
				{
					resetmotors();
					turnDegrees('s', encodersetpoint - doublestraight * straighttarget, reversemotortarget, reversemotortarget);
					resetmotors();
					sensorvalues();
					nogreenset();
				}
				else
				{
					sensorvalues();
					nogreenset();
				}
			}
		}
		else
		{
			resetmotors();
			turnDegrees('s', straighttarget, motortarget, motortarget);
			resetmotors();
			sensorvalues();
			if (avalue < sensoraverage)
			{
				resetmotors();
				turnDegrees('s', straighttarget, motortarget, motortarget);
				resetmotors();
				turnDegrees('r', singletarget, motortarget, greenturn);
				resetmotors();
				sensorvalues();
				while (xvalue > sensoraverage)
				{
					motor[motorB] = motortarget;
					motor[motorC] = greenturn;
					sensorvalues();
				}
				resetmotors();
				sensorvalues();
				nogreenset();
			}
			else
			{
				resetmotors();
				sensorvalues();
				if (xvalue > sensoraverage && avalue > sensoraverage)
				{
					resetmotors();
					turnDegrees('s', encodersetpoint - doublestraight * straighttarget, reversemotortarget, reversemotortarget);
					resetmotors();
					sensorvalues();
					while(xvalue > turnlimit)
					{
						sensorvalues();
						motor[motorB] = motortarget;
						motor[motorC] = nosquare;
					}
					resetmotors();
					turnDegrees('s', straighttarget, motortarget, motortarget);
					resetmotors();
					sensorvalues();
					nogreenset();
				}
				else
				{
					sensorvalues();
					nogreenset();
				}
			}
		}
	}
	else
	{
		resetmotors();
		turnDegrees('s', straighttarget, motortarget, motortarget);
		resetmotors();
		sensorvalues();
		nogreenset();
	}
	nogreenset();
}
#endif
