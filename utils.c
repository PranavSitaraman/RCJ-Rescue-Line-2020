#ifndef _UTILS_
#define _UTILS_
void turnDegrees(char q, float degrees, int powB, int powC)
{
	if (q == 'l' && powC < 0)
	{
		while(nMotorEncoder[motorC] > wheelbase/wheeldiameter * degrees)
		{
			motor[motorB] = powB;
			motor[motorC] = powC;
		}
	}
	else if (q == 'l' && powC >= 0)
	{
		while(nMotorEncoder[motorC] < wheelbase/wheeldiameter * degrees)
		{
			motor[motorB] = powB;
			motor[motorC] = powC;
		}
	}
	else if (q == 'r' && powB < 0)
	{
			while(nMotorEncoder[motorB] > (wheelbase/wheeldiameter) * degrees)
			{
				motor[motorB] = powB;
				motor[motorC] = powC;
			}
	}
	else if (q == 'r' && powB >= 0)
	{
		while(nMotorEncoder[motorB] < wheelbase/wheeldiameter * degrees)
		{
			motor[motorB] = powB;
			motor[motorC] = powC;
		}
	}
	else if (q == 's' && powB < 0)
	{
		while(nMotorEncoder[motorB] > 360/(wheeldiameter * PI) * degrees)
		{
			motor[motorB] = powB;
			motor[motorC] = powC;
		}
	}
	else if (q == 's' && powB >= 0)
	{
		while(nMotorEncoder[motorB] < 360/(wheeldiameter * PI) * degrees)
		{
			motor[motorB] = powB;
			motor[motorC] = powC;
		}
	}
}
void sensorvalues()
{
	getColorRGB(S2, x, y, z);
	getColorRGB(S3, a, b, c);
	getColorRGB(S1, t, u, v);
	xvalue = (float)(x);
	yvalue = (float)(y);
	zvalue = (float)(z);
	avalue = (float)(a);
	bvalue = (float)(b);
	cvalue = (float)(c);
	tvalue = (float)(t);
	uvalue = (float)(u);
	vvalue = (float)(v);
}
void resetmotors()
{
	motor[motorA] = 0;
	motor[motorB] = 0;
	motor[motorC] = 0;
	nMotorEncoder[motorA] = 0;
	nMotorEncoder[motorB] = 0;
	nMotorEncoder[motorC] = 0;
}
void findgreen()
{
	leftratio = (yvalue + sensordiff)/(xvalue + sensordiff);
	rightratio = (bvalue + sensordiff)/(avalue + sensordiff);
	if (leftratio > leftgreenlower && leftratio < leftgreenupper && yvalue > greenaverage)
	{
		l = 1;
	}
	else
	{
		l = 0;
	}
	if (rightratio > rightgreenlower && rightratio < rightgreenupper && bvalue > greenaverage)
	{
		r = 1;
	}
	else
	{
		r = 0;
	}
	lastxvalue = xvalue;
	lastavalue = avalue;
}
void nogreenset()
{
	l = 0;
	r = 0;
}
#endif
