#pragma config(Motor,  motor1,          LeftForwardMotorA, tmotorVexIQ, openLoop, reversed, driveLeft)
#pragma config(Motor,  motor2,          LeftMiddleMotorA, tmotorVexIQ, openLoop, reversed, driveLeft)
#pragma config(Motor,  motor3,          LeftRearMotorA, tmotorVexIQ, openLoop, reversed, driveLeft)
#pragma config(Motor,  motor4,          LeftForwardMotorD, tmotorVexIQ, openLoop, driveLeft)
#pragma config(Motor,  motor5,          LeftRearMotorD, tmotorVexIQ, openLoop, driveLeft)
#pragma config(Motor,  motor6,          RightForwarMotorD, tmotorVexIQ, openLoop, reversed, driveRight)
#pragma config(Motor,  motor7,          RightRearMotorD, tmotorVexIQ, openLoop, reversed, driveRight)
#pragma config(Motor,  motor8,          RightForwardMotorA, tmotorVexIQ, openLoop, driveRight)
#pragma config(Motor,  motor9,          RightMiddleMotorA, tmotorVexIQ, openLoop, driveRight)
#pragma config(Motor,  motor10,         RightRearMotorA, tmotorVexIQ, openLoop, driveRight)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
	while(1==1)
	{
		motor[Leftforwarddrivemotor] = vexRT[Ch3];

	}
}