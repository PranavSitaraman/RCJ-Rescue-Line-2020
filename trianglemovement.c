#ifndef _TRIANGLEMOV_
#define _TRIANGLEMOV_
// bring ball to black triangle
void trianglemovement()
{
	for (int w = 0; w < sizeof(array)/sizeof(array[0]); w++)
	{
		for (int ww = 0; ww < sizeof(array[0])/sizeof(array[0][0]); ww++)
		{
			if (array[w][ww] == trianglearray)
			{
				trianglelocationi = w;
				trianglelocationii = ww;
			}
		}
	}
	width = grid * (trianglelocationi - robotlocationi);
	height = grid * (trianglelocationii - robotlocationii);
	diagonal = sqrt(width * width + height * height);
	if (startturndirection == 'l')
	{
		if (width < 0)
		{
			if (height < 0)
			{
				if (direction == "up")
				{
					// 1
				}
				else if (direction == "down")
				{
					// 2
				}
				else if (direction == "right")
				{
					// 3
				}
			}
			else if (height == 0)
			{
				if (direction == "up")
				{
					// 4
				}
				else if (direction == "down")
				{
					// 5
				}
				else if (direction == "right")
				{
					// 6
				}
			}
			else if (height > 0)
			{
				if (direction == "up")
				{
					// 7
				}
				else if (direction == "down")
				{
					// 8
				}
				else if (direction == "right")
				{
					// 9
				}
			}
		}
		else if (width == 0)
		{
			if (height < 0)
			{
				if (direction == "up")
				{
					// 10
				}
				else if (direction == "down")
				{
					// 11
				}
				else if (direction == "right")
				{
					// 12
				}
			}
			else if (height == 0)
			{
				if (direction == "up")
				{
					// 13
				}
				else if (direction == "down")
				{
					// 14
				}
				else if (direction == "right")
				{
					// 15
				}
			}
			else if (height > 0)
			{
				if (direction == "up")
				{
					// 16
				}
				else if (direction == "down")
				{
					// 17
				}
				else if (direction == "right")
				{
					// 18
				}
			}
		}
		else if (width > 0)
		{
			if (height < 0)
			{
				if (direction == "up")
				{
					// 19
				}
				else if (direction == "down")
				{
					// 20
				}
				else if (direction == "right")
				{
					// 21
				}
			}
			else if (height == 0)
			{
				if (direction == "up")
				{
					// 22
				}
				else if (direction == "down")
				{
					// 23
				}
				else if (direction == "right")
				{
					// 24
				}
			}
			else if (height > 0)
			{
				if (direction == "up")
				{
					// 25
				}
				else if (direction == "down")
				{
					// 26
				}
				else if (direction == "right")
				{
					// 27
				}
			}
		}
	}
	else if (startturndirection == 'r')
	{
		if (width < 0)
		{
			if (height < 0)
			{
				if (direction == "up")
				{
					// 28
				}
				else if (direction == "down")
				{
					// 29
				}
				else if (direction == "right")
				{
					// 30
				}
			}
			else if (height == 0)
			{
				if (direction == "up")
				{
					// 31
				}
				else if (direction == "down")
				{
					// 32
				}
				else if (direction == "right")
				{
					// 33
				}
			}
			else if (height > 0)
			{
				if (direction == "up")
				{
					// 34
				}
				else if (direction == "down")
				{
					// 35
				}
				else if (direction == "right")
				{
					// 36
				}
			}
		}
		else if (width == 0)
		{
			if (height < 0)
			{
				if (direction == "up")
				{
					// 37
				}
				else if (direction == "down")
				{
					// 38
				}
				else if (direction == "right")
				{
					// 39
				}
			}
			else if (height == 0)
			{
				if (direction == "up")
				{
					// 40
				}
				else if (direction == "down")
				{
					// 41
				}
				else if (direction == "right")
				{
					// 42
				}
			}
			else if (height > 0)
			{
				if (direction == "up")
				{
					// 43
				}
				else if (direction == "down")
				{
					// 44
				}
				else if (direction == "right")
				{
					// 45
				}
			}
		}
		else if (width > 0)
		{
			if (height < 0)
			{
				if (direction == "up")
				{
					// 46
				}
				else if (direction == "down")
				{
					// 47
				}
				else if (direction == "right")
				{
					// 48
				}
			}
			else if (height == 0)
			{
				if (direction == "up")
				{
					// 49
				}
				else if (direction == "down")
				{
					// 50
				}
				else if (direction == "right")
				{
					// 51
				}
			}
			else if (height > 0)
			{
				if (direction == "up")
				{
					// 52
				}
				else if (direction == "down")
				{
					// 53
				}
				else if (direction == "right")
				{
					// 54
				}
			}
		}
	}
}
#endif
