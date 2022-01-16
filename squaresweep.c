#ifndef _SQUARESWEEP_
#define _SQUARESWEEP_
void squaresweep()
{
	resetmotors();
	turnDegrees('l', turntarget, reversemotortarget, motortarget);
	resetmotors();
	for (s = 1; s < 15; s++)
	{
		resetmotors();
		turnDegrees('r', rightangle/7, motortarget, reversemotortarget);
		resetmotors();
		if (rightangle/7 * s < acos(1/sqrt(5)) * (rightangle * 2)/PI)
		{
			resetmotors();
			while(nMotorEncoder[motorB] < 360/(wheeldiameter * PI) * (halfgrid/cosDegrees(rightangle/7 * s) - sensordistance) && SensorValue(S1) >= 640)
			{
				motor[motorB] = motortarget;
				motor[motorC] = motortarget;
			}
			motor[motorB] = 0;
			motor[motorC] = 0;
			if (SensorValue(S1) < 640)
			{
				motor[motorA] = 0;
				nMotorEncoder[motorA] = 0;
				while (nMotorEncoder[motorA] > closeclaw)
				{
					motor[motorA] = reversemotortarget;
				}
				motor[motorA] = 0;
				nMotorEncoder[motorA] = 0;
				ball = true;
				while(nMotorEncoder[motorB] < 360/(wheeldiameter * PI) * (halfgrid/cosDegrees(rightangle/7 * s) - sensordistance))
				{
					motor[motorB] = motortarget;
					motor[motorC] = motortarget;
				}
			}
			resetmotors();
			while(nMotorEncoder[motorB] > -360/(wheeldiameter * PI) * (halfgrid/cosDegrees(rightangle/7 * s) - sensordistance))
			{
				motor[motorB] = reversemotortarget;
				motor[motorC] = reversemotortarget;
			}
			resetmotors();
		}
		else if (rightangle/7 * s > acos(1/sqrt(5)) * rightangle * 2/PI && rightangle/7 * s < rightangle)
		{
			resetmotors();
			while(nMotorEncoder[motorB] < 360/(wheeldiameter * PI) * (grid/cosDegrees(rightangle - rightangle/7 * s) - sensordistance) && SensorValue(S1) >= 640)
			{
				motor[motorB] = motortarget;
				motor[motorC] = motortarget;
			}
			if (SensorValue(S1) < 640)
			{
				motor[motorA] = 0;
				nMotorEncoder[motorA] = 0;
				while (nMotorEncoder[motorA] > closeclaw)
				{
					motor[motorA] = reversemotortarget;
				}
				motor[motorA] = 0;
				nMotorEncoder[motorA] = 0;
				ball = true;
				while(nMotorEncoder[motorB] < 360/(wheeldiameter * PI) * (grid/cosDegrees(rightangle - rightangle/7 * s) - sensordistance))
				{
					motor[motorB] = motortarget;
					motor[motorC] = motortarget;
				}
			}
			resetmotors();
			while(nMotorEncoder[motorB] > -360/(wheeldiameter * PI) * (grid/cosDegrees(rightangle - rightangle/7 * s) - sensordistance))
			{
				motor[motorB] = reversemotortarget;
				motor[motorC] = reversemotortarget;
			}
			resetmotors();
		}
		else if (rightangle/7 * s >= rightangle && rightangle/7 * s < rightangle * 2 - acos(1/sqrt(5)) * rightangle * 2/PI)
		{
			resetmotors();
			while(nMotorEncoder[motorB] < 360/(wheeldiameter * PI) * (grid/cosDegrees(rightangle/7 * s - rightangle) - sensordistance) && SensorValue(S1) >= 640)
			{
				motor[motorB] = motortarget;
				motor[motorC] = motortarget;
			}
			if (SensorValue(S1) < 640)
			{
				motor[motorA] = 0;
				nMotorEncoder[motorA] = 0;
				while (nMotorEncoder[motorA] > closeclaw)
				{
					motor[motorA] = reversemotortarget;
				}
				motor[motorA] = 0;
				nMotorEncoder[motorA] = 0;
				ball = true;
				while(nMotorEncoder[motorB] < 360/(wheeldiameter * PI) * (grid/cosDegrees(rightangle/7 * s - rightangle) - sensordistance))
				{
					motor[motorB] = motortarget;
					motor[motorC] = motortarget;
				}
			}
			resetmotors();
			while(nMotorEncoder[motorB] > -360/(wheeldiameter * PI) * (grid/cosDegrees(rightangle/7 * s - rightangle) - sensordistance))
			{
				motor[motorB] = reversemotortarget;
				motor[motorC] = reversemotortarget;
			}
			resetmotors();
		}
		else if (rightangle/7 * s > rightangle * 2 - acos(1/sqrt(5)) * rightangle * 2/PI)
		{
			resetmotors();
			while(nMotorEncoder[motorB] < 360/(wheeldiameter * PI) * (halfgrid/cosDegrees(2 * rightangle - rightangle/7 * s) - sensordistance) && SensorValue(S1) >= 640)
			{
				motor[motorB] = motortarget;
				motor[motorC] = motortarget;
			}
			if (SensorValue(S1) < 640)
			{
				motor[motorA] = 0;
				nMotorEncoder[motorA] = 0;
				while (nMotorEncoder[motorA] > closeclaw)
				{
					motor[motorA] = reversemotortarget;
				}
				motor[motorA] = 0;
				nMotorEncoder[motorA] = 0;
				ball = true;
				while(nMotorEncoder[motorB] < 360/(wheeldiameter * PI) * (halfgrid/cosDegrees(2 * rightangle - rightangle/7 * s) - sensordistance))
				{
					motor[motorB] = motortarget;
					motor[motorC] = motortarget;
				}
			}
			resetmotors();
			while(nMotorEncoder[motorB] > -360/(wheeldiameter * PI) * (halfgrid/cosDegrees(2 * rightangle - rightangle/7 * s) - sensordistance))
			{
				motor[motorB] = reversemotortarget;
				motor[motorC] = reversemotortarget;
			}
			resetmotors();
		}
	}
	resetmotors();
	turnDegrees('l', turntarget, reversemotortarget, motortarget);
	resetmotors();
	if (ball == true)
	{
		ball = false;
		trianglemovement();
	}
	resetmotors();
	turnDegrees('s', halfgrid, motortarget, motortarget);
	resetmotors();
}
#endif
