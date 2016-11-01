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
#pragma autonomousDuration(0)
#pragma userControlDuration(60)

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!

void pre_auton()
{
 	//Don't change the below line of code
  bStopTasksBetweenModes = true;
  //If needed, insert preaction code (clearing sensors, etc..) below this comment

}

task autonomous()
{
	AutonomousCodePlaceholderForTesting(); //keep this line of code
}

task usercontrol()
{
	//put remote control code in the while loop
	while(true)
  {
    //Right side drive (main controller)
    motor[rightFront] = vexRT[Ch2]/2;
		motor[rightBack] = vexRT[Ch2]/2;
    //Left side drive (main controller)
    motor[leftFront] = vexRT[Ch3]/2;
		motor[leftBack] = vexRT[Ch3]/2;
  	//Shooter control varying speeds (partner controller)
    //Full Speed (127)
    if(vexRT[Btn8UXmtr2] == 1)
		{
			motor[leftTop] = 127;
			motor[leftBottom] = 127;
			motor[rightTop] = 127;
			motor[rightBottom] = 127;
		}
    //Little less speed (95)
    else if(vexRT[Btn8DXmtr2] == 1)
		{
			motor[leftTop] = 105;
			motor[leftBottom] = 105;
			motor[rightTop] = 105;
			motor[rightBottom] = 105;
		}
    //Lesser Speed (80)
    else if(vexRT[Btn7UXmtr2] == 1)
		{
			motor[leftTop] = 85;
			motor[leftBottom] = 85;
			motor[rightTop] = 85;
			motor[rightBottom] = 85;
		}
    //Slow Speed (65)
    if(vexRT[Btn7DXmtr2] == 1)
		{
			motor[leftTop] = 65;
			motor[leftBottom] = 65;
			motor[rightTop] = 65;
			motor[rightBottom] = 65;
		}

    else
    {
    	motor[leftTop] = 0;
			motor[leftBottom] = 0;
			motor[rightTop] = 0;
			motor[rightBottom] = 0;
    }
  }
}
