#ifndef _EVACUATION_
#define _EVACUATION_
void evacuation()
{
	delay(5000);
	resetmotors();
	sensorvalues();
	findgreen();
	cornerfind();
	walltrace();
	snakemotion();
}
#endif
