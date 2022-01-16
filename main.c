#pragma config(Sensor, S1,     colorSensor,    sensorEV3_Color, modeEV3Color_Reflected_Raw)
#pragma config(Sensor, S2,     colorSensor,    sensorEV3_Color, modeEV3Color_RGB_Raw)
#pragma config(Sensor, S3,     colorSensor,    sensorEV3_Color, modeEV3Color_RGB_Raw)
#pragma config(Sensor, S4,     sonarSensor,    sensorEV3_IRSensor)
#pragma config(Motor,  motorA,          mediumMotor,   tmotorEV3_Medium, PIDControl, encoder)
#pragma config(Motor,  motorB,          leftMotor,     tmotorEV3_Large, PIDControl, driveLeft, encoder)
#pragma config(Motor,  motorC,          rightMotor,    tmotorEV3_Large, PIDControl, driveRight, encoder)
#include "global.h"
#include "utils.c"
#include "obstacle.c"
#include "linetracing.c"
#include "green.c"
#include "gap.c"
#include "course1.c"
#include "course2.c"
#include "cornerfind.c"
#include "walltrace.c"
#include "trianglemovement.c"
#include "squaresweep.c"
#include "snakemotion.c"
#include "evacuation.c"
#include "fullrun.c"
task main()
{
	fullrun();
}
