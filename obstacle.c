#ifndef _OBJ_
#define _OBJ_
void obstacle()
{
	if (SensorValue[S4] < forwardsensor)
	{
		resetmotors();
		turnDegrees('l', obstacleturn, reverseobstaclemotor, obstaclemotor);
		resetmotors();
		if (SensorValue[S4] < threshold)
		{
			resetmotors();
			turnDegrees('r', leftrightratio * obstacleturn, obstaclemotor, reverseobstaclemotor);
			resetmotors();
			g = 2;
		}
		if (g == 1)
		{
			motor[motorB] = outer;
			motor[motorC] = inner;
		}
		else if (g == 2)
		{
			motor[motorB] = inner;
			motor[motorC] = outer;
		}
		resetmotors();
		sensorvalues();
		while (xvalue > sensoraverage && avalue > sensoraverage)
		{
			if (g == 1)
			{
				motor[motorB] = outer;
				motor[motorC] = inner;
			}
			else if (g == 2)
			{
				motor[motorB] = inner;
				motor[motorC] = outer;
			}
			sensorvalues();
		}
		resetmotors();
		if (g == 1)
		{
			turnDegrees('l', smallobstacleturn, 0, obstaclemotor);
		}
		else if (g == 2)
		{
			turnDegrees('r', smallobstacleturn, obstaclemotor, 0);
		}
		resetmotors();
	}
}
#endif
