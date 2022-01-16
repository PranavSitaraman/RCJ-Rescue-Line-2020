#ifndef _LINE_
#define _LINE_
void linetracing()
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
	if (xvalue < sensoraverage && avalue < sensoraverage)
	{
		resetmotors();
		turnDegrees('s', 2 * straighttarget, motortarget, motortarget);
		resetmotors();
		turnDegrees('l', smallturntarget, greenturn, motortarget);
		sensorvalues();
		if (avalue < sensoraverage)
		{
			sensorvalues();
			findgreen();
		}
		else if (xvalue < sensoraverage)
		{
			sensorvalues();
			findgreen();
		}
		else
		{
			resetmotors();
			turnDegrees('l', -smallturntarget, reversegreenturn, reversemotortarget);
			resetmotors();
			turnDegrees('r', smallturntarget, motortarget, greenturn);
			if (avalue < sensoraverage)
			{
				sensorvalues();
				findgreen();
			}
			else if (xvalue < sensoraverage)
			{
				sensorvalues();
				findgreen();
			}
			else
			{
				resetmotors();
				turnDegrees('r', -smallturntarget, reversemotortarget, reversegreenturn);
				resetmotors();
				sensorvalues();
				while (xvalue > sensoraverage && avalue > sensoraverage)
				{
					motor[motorB] = reversemotortarget;
					motor[motorC] = reversemotortarget;
					sensorvalues();
				}
				sensorvalues();
				resetmotors();
				turnDegrees('s', verysmallstraighttarget, motortarget, motortarget);
				resetmotors();
				if (xvalue <= sensoraverage)
				{
					while(nMotorEncoder[motorC] < checkturntarget * wheelbase/wheeldiameter && avalue > sensoraverage && xvalue > smallsensoraverage)
					{
						motor[motorC] = motortarget;
						motor[motorB] = reversecheckturn;
						sensorvalues();
					}
					resetmotors();
					if (avalue <= sensoraverage || xvalue <= sensoraverage)
					{
						sensorvalues();
						findgreen();
					}
					else
					{
						resetmotors();
						turnDegrees('r', largecheckturntarget, checkturn, reversemotortarget);
						resetmotors();
						while(nMotorEncoder[motorB] < checkturntarget * wheelbase/wheeldiameter && xvalue > sensoraverage && avalue > smallsensoraverage)
						{
							motor[motorB] = motortarget;
							motor[motorC] = reversecheckturn;
							sensorvalues();
						}
						resetmotors();
						sensorvalues();
						findgreen();
					}
				}
				else
				{
					while(nMotorEncoder[motorB] < checkturntarget * wheelbase/wheeldiameter && xvalue > sensoraverage && avalue > smallsensoraverage)
					{
						motor[motorC] = reversecheckturn;
						motor[motorB] = motortarget;
						sensorvalues();
					}
					resetmotors();
					if (xvalue <= sensoraverage || avalue <= sensoraverage)
					{
						sensorvalues();
						findgreen();
					}
					else
					{
						resetmotors();
						turnDegrees('l', largecheckturntarget, reversemotortarget, checkturn);
						resetmotors();
						while(nMotorEncoder[motorC] < checkturntarget * wheelbase/wheeldiameter && avalue > smallsensoraverage && xvalue > sensoraverage)
						{
							motor[motorC] = motortarget;
							motor[motorB] = reversecheckturn;
							sensorvalues();
						}
						resetmotors();
						sensorvalues();
						findgreen();
					}
				}
			}
		}
	}
	else
	{
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
		findgreen();
	}
}
#endif
