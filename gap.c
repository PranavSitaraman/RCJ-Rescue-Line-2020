#ifndef _GAP_
#define _GAP_
void gap()
{
	sensorvalues();
	if (xvalue < sensoraverage || avalue < sensoraverage)
	{
		leftencoder = nMotorEncoder[motorB];
		rightencoder = nMotorEncoder[motorC];
	}
	if (nMotorEncoder[motorB] >= leftencoder + 360/(wheeldiameter * PI) * gapdistance || nMotorEncoder[motorC] >= rightencoder + 360/(wheeldiameter * PI) * gapdistance)
	{
		resetmotors();
		while(nMotorEncoder[motorC] < wheelbase/wheeldiameter * gapturncheck * smallturntarget && xvalue > sensoraverage && avalue > sensoraverage)
		{
			motor[motorB] = greenturn;
			motor[motorC] = motortarget;
			sensorvalues();
		}
		sensorvalues();
		if (avalue <= sensoraverage)
		{
			sensorvalues();
			findgreen();
		}
		else if (xvalue <= sensoraverage)
		{
			sensorvalues();
			findgreen();
		}
		else
		{
			resetmotors();
			turnDegrees('l', -gapturncheck * smallturntarget, reversegreenturn, reversemotortarget);
			resetmotors();
			while(nMotorEncoder[motorB] < wheelbase/wheeldiameter * gapturncheck * smallturntarget && xvalue > sensoraverage && avalue > sensoraverage)
			{
				motor[motorB] = motortarget;
				motor[motorC] = greenturn;
				sensorvalues();
			}
			sensorvalues();
			if (avalue <= sensoraverage)
			{
				sensorvalues();
				findgreen();
			}
			else if (xvalue <= sensoraverage)
			{
				sensorvalues();
				findgreen();
			}
			else
			{
				resetmotors();
				turnDegrees('r', -gapturncheck * smallturntarget, reversemotortarget, reversegreenturn);
				resetmotors();
				sensorvalues();
				if (xvalue >= sensoraverage || avalue >= sensoraverage)
				{
					turnDegrees('r', turnaroundtarget - smallturntarget, motortarget, reversemotortarget);
					sensorvalues();
					resetmotors();
					while (xvalue>sensoraverage && avalue>sensoraverage && nMotorEncoder[motorC] < 360/(wheeldiameter * PI) * 1/4)
					{
						motor[motorB] = motortarget;
						motor[motorC] = motortarget;
						sensorvalues();
					}
					resetmotors();
					while (gapcounter<gapcounterlimit)
					{
						sensorvalues();
						if (tardownlimit < xvalue - avalue && xvalue - avalue < taruplimit)
						{
							tar = xvalue - avalue;
						}
						else
						{
							tar = leftvalue - rightvalue;
						}
						error = xvalue - avalue - tar;
						integral = integral + error;
						if (error < derivativesetpoint)
						{
							derivative = derivativesetpoint - (fabs(error - lastError))/2;
						}
						else
						{
							derivative = (fabs(error - lastError))/2;
						}
						turn = Kp * error + Ki * integral + Kd * derivative;
						powerB = motortarget + (2 * turn);
						powerC = motortarget - (2 * turn);
						motor[motorB] = powerB;
						motor[motorC] = powerC;
						lastError = error;
						if (integral > integraluplimit)
						{
							integral = integraltarget;
						}
						else if (integral < integraldownlimit)
						{
							integral = integraltarget;
						}
						sensorvalues();
						gapcounter++;
					}
					gapcounter = 0;
					resetmotors();
					turnDegrees('r', turnaroundtarget - smallturntarget, motortarget, reversemotortarget);
					resetmotors();
					while (xvalue>sensoraverage && avalue>sensoraverage)
					{
						motor[motorB] = motortarget;
						motor[motorC] = motortarget;
						sensorvalues();
					}
					leftencoder = nMotorEncoder[motorB];
					rightencoder = nMotorEncoder[motorC];
					resetmotors();
					sensorvalues();
					while (gapcounter<gapcounterlimit)
					{
						sensorvalues();
						if (tardownlimit < xvalue - avalue && xvalue - avalue < taruplimit)
						{
							tar = xvalue - avalue;
						}
						else
						{
							tar = leftvalue - rightvalue;
						}
						error = xvalue - avalue - tar;
						integral = integral + error;
						if (error < derivativesetpoint)
						{
							derivative = derivativesetpoint - (fabs(error - lastError))/2;
						}
						else
						{
							derivative = (fabs(error - lastError))/2;
						}
						turn = Kp * error + Ki * integral + Kd * derivative;
						powerB = motortarget + turn;
						powerC = motortarget - turn;
						motor[motorB] = powerB;
						motor[motorC] = powerC;
						lastError = error;
						if (integral > integraluplimit)
						{
							integral = integraltarget;
						}
						else if (integral < integraldownlimit)
						{
							integral = integraltarget;
						}
						sensorvalues();
						gapcounter++;
					}
					resetmotors();
					sensorvalues();
				}
			}
		}
	}
}
#endif
