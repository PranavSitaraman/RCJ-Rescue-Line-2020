#ifndef _SNAKEMOTION_
#define _SNAKEMOTION_
void snakemotion()
{
	if (length == 3)
	{
		length = 4;
	}
	else if (length == 4)
	{
		length = 3;
	}
	resetmotors();
	turnDegrees('s', halfgrid, motortarget, motortarget);
	resetmotors();
	robotlocationi = 0;
	robotlocationii++;
	direction = "up";
	squaresweep();
	resetmotors();
	turnDegrees('s', halfgrid, motortarget, motortarget);
	resetmotors();
	robotlocationi = 0;
	robotlocationii++;
	direction = "up";
	squaresweep();
	if (length == 4)
	{
		resetmotors();
		turnDegrees('s', halfgrid, motortarget, motortarget);
		resetmotors();
		robotlocationi = 0;
		robotlocationii++;
		direction = "up";
		squaresweep();
	}
	resetmotors();
	if (startturndirection == 'l')
	{
		turnDegrees('r', turntarget, motortarget, reversemotortarget);
	}
	else if (startturndirection == 'r')
	{
		turnDegrees('l', turntarget, reversemotortarget, motortarget);
	}
	resetmotors();
	turnDegrees('s', halfgrid, motortarget, motortarget);
	resetmotors();
	robotlocationi = 1;
	if (startturndirection == 'l')
	{
		direction = "right";
	}
	else if (startturndirection=='r')
	{
		direction = "left";
	}
	squaresweep();
	resetmotors();
	if (startturndirection == 'l')
	{
		turnDegrees('r', turntarget, motortarget, reversemotortarget);
	}
	else if (startturndirection == 'r')
	{
		turnDegrees('l', turntarget, reversemotortarget, motortarget);
	}
	resetmotors();
	turnDegrees('s', halfgrid, motortarget, motortarget);
	resetmotors();
	robotlocationi = 1;
	robotlocationii--;
	direction = "down";
	squaresweep();
	resetmotors();
	turnDegrees('s', halfgrid, motortarget, motortarget);
	resetmotors();
	robotlocationi = 1;
	robotlocationii--;
	direction = "down";
	squaresweep();
	if (length == 4)
	{
		resetmotors();
		turnDegrees('s', halfgrid, motortarget, motortarget);
		resetmotors();
		robotlocationi = 0;
		robotlocationii--;
		direction = "down";
		squaresweep();
	}
	resetmotors();
	if (startturndirection == 'l')
	{
		turnDegrees('l', turntarget, reversemotortarget, motortarget);
	}
	else if (startturndirection == 'r')
	{
		turnDegrees('r', turntarget, motortarget, reversemotortarget);
	}
	resetmotors();
	turnDegrees('s', halfgrid, motortarget, motortarget);
	resetmotors();
	robotlocationi = 2;
	if (startturndirection == 'l')
	{
		direction = "right";
	}
	else if (startturndirection == 'r')
	{
		direction = "left";
	}
	squaresweep();
	resetmotors();
	if (startturndirection == 'l')
	{
		turnDegrees('l', turntarget, reversemotortarget, motortarget);
	}
	else if (startturndirection == 'r')
	{
		turnDegrees('r', turntarget, motortarget, reversemotortarget);
	}
	resetmotors();
	turnDegrees('s', halfgrid, motortarget, motortarget);
	resetmotors();
	robotlocationi = 2;
	robotlocationii++;
	direction = "up";
	squaresweep();
	resetmotors();
	turnDegrees('s', halfgrid, motortarget, motortarget);
	resetmotors();
	robotlocationi = 2;
	robotlocationii++;
	direction = "up";
	squaresweep();
	if (length == 4)
	{
		resetmotors();
		turnDegrees('s', halfgrid, motortarget, motortarget);
		resetmotors();
		robotlocationi = 2;
		robotlocationii++;
		direction = "up";
		squaresweep();
	}
	if (length == 3)
	{
		resetmotors();
		if (startturndirection == 'l')
		{
			turnDegrees('r', turntarget, motortarget, reversemotortarget);
		}
		else if (startturndirection == 'r')
		{
			turnDegrees('l', turntarget, reversemotortarget, motortarget);
		}
		resetmotors();
		turnDegrees('s', halfgrid, motortarget, motortarget);
		resetmotors();
		robotlocationi = 3;
		if (startturndirection == 'l')
		{
			direction = "right";
		}
		else if (startturndirection == 'r')
		{
			direction = "left";
		}
		squaresweep();
		resetmotors();
		if (startturndirection == 'l')
		{
			turnDegrees('r', turntarget, motortarget, reversemotortarget);
		}
		else if (startturndirection == 'r')
		{
			turnDegrees('l', turntarget, reversemotortarget, motortarget);
		}
		resetmotors();
		turnDegrees('s', halfgrid, motortarget, motortarget);
		resetmotors();
		robotlocationi = 3;
		robotlocationii--;
		direction = "down";
		squaresweep();
		resetmotors();
		turnDegrees('s', halfgrid, motortarget, motortarget);
		resetmotors();
		robotlocationi = 3;
		robotlocationii--;
		direction = "down";
		squaresweep();
		if (length == 4)
		{
			resetmotors();
			turnDegrees('s', halfgrid, motortarget, motortarget);
			resetmotors();
			robotlocationi = 3;
			robotlocationii--;
			direction = "down";
			squaresweep();
		}
	}
}
#endif
