#ifndef _GLOBAL_
#define _GLOBAL_
float	wheelbase = 7.5;
float	wheeldiameter = 1.2;
float	Kp = 5.75;
float	Ki = 0.01;
float	Kd = 0.1;
float	leftvalue = 60;
float	rightvalue = 63;
float	sensoraverage = 20;
float	integraluplimit = 50;
float	taruplimit = 25;
float	obstaclemotor = 50;
float	checkturn = 20;
float	tar = leftvalue - rightvalue;
float error;
float turn;
float powerB;
float powerC;
float	tardownlimit = -taruplimit;
float	integraldownlimit = -integraluplimit;
float	integral = 0;
float	integraltarget = 0;
float	derivative = 0;
float	motortarget = 30;
float leftencoder = nMotorEncoder[motorB];
float rightencoder = nMotorEncoder[motorC];
float	reversemotortarget = -motortarget;
float	derivativesetpoint = 0;
float	lastError = 0;
float	reverseobstaclemotor = -obstaclemotor;
float	nosquare = -motortarget + 8;
float	greenturn = -motortarget + 8;
float	reversegreenturn = -greenturn;
float	encodersetpoint = 0;
float	reversecheckturn = -checkturn;
long x;
long y;
long z;
long a;
long b;
long c;
long t;
long u;
long v;
float xvalue;
float yvalue;
float zvalue;
float avalue;
float bvalue;
float cvalue;
float tvalue;
float uvalue;
float vvalue;
float leftratio;
float rightratio;
float lastxvalue;
float lastavalue;
float	leftgreenlower = 2;
float	leftgreenupper = 6;
float	rightgreenlower = 1.5;
float	rightgreenupper = 5.5;
float	sensordiff = 0.01;
float	smallsensoraverage = sensoraverage/2;
float	greenaverage = 15;
float l;
float r;
float	turnlimit = 14;
float obstacleturn = 65;
float	smallobstacleturn = 20;
float turntarget = 80;
float	largecheckturntarget = 90;
float	checkturntarget = 130;
float doubletarget = 120;
float singletarget = 55;
float	straighttarget = 0.78;
float	doublegreenstraighttarget = 0.2;
float	verysmallstraighttarget = 0.3;
float	greenstraighttarget = 1;
float	turnaroundtarget = 160;
float	doublestraight = 2;
float smallturntarget = 10;
float gapdistance = 4.25;
float gapturncheck = 1.7;
float gapcounter = 0;
float gapcounterlimit = 350;
float obsr = 3;
float threshold = 35;
float g = 1;
float h = 50;
float	buffer = 0;
float	inner = ((obsr + buffer)/(obsr + buffer + wheelbase)) * h;
float	outer = h;
float	leftrightratio = 1.7;
float	forwardsensor = 15;
float silvervalue = 80;
char startturndirection = NULL;
float walldistance = 20;
int entrancearray = 2;
int exitarray = 3;
int emptyarray = 1;
int trianglearray = 4;
int entrance = 0;
int exit = 0;
int triangle = 0;
int array[4][4];
int length = (3);
float grid = 11;
float halfgrid = grid/2;
long right;
long left;
int robotlocationi = 0;
int robotlocationii = 0;
int openclaw = 450;
int closeclaw = -openclaw;
int s;
int trianglelocationi;
int trianglelocationii;
int width;
int height;
int diagonal;
int sensordistance = 5;
int rightangle = 90;
string direction;
bool ball = false;
#endif
