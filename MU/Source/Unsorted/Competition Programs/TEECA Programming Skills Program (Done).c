#pragma config(Motor,  port1,           leftBottom,    tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           leftTop,       tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           rightFront,    tmotorVex393_MC29, openLoop, reversed, driveRight)
#pragma config(Motor,  port4,           rightBack,     tmotorVex393_MC29, openLoop, reversed, driveRight)
#pragma config(Motor,  port5,           leftFront,     tmotorVex393_MC29, openLoop, driveLeft)
#pragma config(Motor,  port6,           leftBack,      tmotorVex393_MC29, openLoop, driveLeft)
#pragma config(Motor,  port9,           rightTop,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          rightBottom,   tmotorVex393_HBridge, openLoop, reversed)
#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(60)
#pragma userControlDuration(0)

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!

void pre_auton()
{
  //Don't change the below line of code
  bStopTasksBetweenModes = true;
  //if needed, insert preaction code (clearing sensors, etc..) below this comment

}

task autonomous()
{
	motor[rightFront] = 90;
	motor[rightBack] = 90;
	motor[leftFront] = 90;
	motor[leftBack] = 90;
	wait1Msec(6000);

	motor[rightFront] = -90;
	motor[rightBack] = -90;
	motor[leftFront] = -90;
	motor[leftBack] = -90;
	wait1Msec(1000);

	motor[rightFront] = 90;
	motor[rightBack] = 90;
	motor[leftFront] = 90;
	motor[leftBack] = 90;
	wait1Msec(1250);

	motor[rightFront] = -90;
	motor[rightBack] = -90;
	motor[leftFront] = -90;
	motor[leftBack] = -90;
	wait1Msec(1000);

	motor[rightFront] = 90;
	motor[rightBack] = 90;
	motor[leftFront] = 90;
	motor[leftBack] = 90;
	wait1Msec(1250);

	motor[rightFront] = -90;
	motor[rightBack] = -90;
	motor[leftFront] = -90;
	motor[leftBack] = -90;
	wait1Msec(1000);

	motor[rightFront] = 0;
	motor[rightBack] = 0;
	motor[leftFront] = 0;
	motor[leftBack] = 0;
	wait1Msec(30000);

}

task usercontrol()
{
	//No user control code needed except the lines of code below this comment
	while (true)
	{
	  UserControlCodePlaceholderForTesting();
	}
}
