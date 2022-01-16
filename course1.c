#ifndef _COURSE1_
#define _COURSE1_
void course1()
{
	sensorvalues();
	findgreen();
	while (xvalue < silvervalue && yvalue < silvervalue && zvalue < silvervalue && avalue < silvervalue && bvalue < silvervalue && cvalue < silvervalue)
	{
		sensorvalues();
		while (l == 0 && r == 0 && xvalue < silvervalue && yvalue < silvervalue && zvalue < silvervalue && avalue < silvervalue && bvalue < silvervalue && cvalue < silvervalue)
		{
			sensorvalues();
			obstacle();
			gap();
			linetracing();
		}
		greensquare();
		sensorvalues();
	}
}
#endif
