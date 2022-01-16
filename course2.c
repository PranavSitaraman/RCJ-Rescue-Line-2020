#ifndef _COURSE2_
#define _COURSE2_
void course2()
{
	sensorvalues();
	while ((xvalue + avalue)/2 < 2 * (yvalue+bvalue))
	{
		sensorvalues();
		while (l == 0 && r == 0 && (xvalue + 2)/2 <  2 * (yvalue + bvalue))
		{
			sensorvalues();
			obstacle();
			gap();
			linetracing();
		}
		greensquare();
	}
}
#endif
