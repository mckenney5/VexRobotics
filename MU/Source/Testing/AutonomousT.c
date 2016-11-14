#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, dgtl1,  TouchSensor,    sensorTouch)
#pragma config(Sensor, I2C_1,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_2,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Motor,  port1,           LeftForwardMotorA, tmotorVex393_HBridge, openLoop, reversed, driveLeft, encoderPort, None)
#pragma config(Motor,  port2,           LeftMiddleMotorA, tmotorVex393_MC29, openLoop, reversed, driveLeft, encoderPort, None)
#pragma config(Motor,  port3,           LeftRearMotorA, tmotorVex393_MC29, openLoop, reversed, driveLeft, encoderPort, I2C_2)
#pragma config(Motor,  port4,           LeftForwardMotorD, tmotorVex393_MC29, openLoop, driveLeft, encoderPort, None)
#pragma config(Motor,  port5,           LeftRearMotorD, tmotorVex393_MC29, openLoop, driveLeft, encoderPort, I2C_1)
#pragma config(Motor,  port6,           RightForwardMotorD, tmotorVex393_MC29, openLoop, reversed, driveRight, encoderPort, None)
#pragma config(Motor,  port7,           RightRearMotorD, tmotorVex393_MC29, openLoop, reversed, driveRight)
#pragma config(Motor,  port8,           RightForwardMotorA, tmotorVex393_MC29, openLoop, driveRight, encoderPort, None)
#pragma config(Motor,  port9,           RightMiddleMotorA, tmotorVex393_MC29, openLoop, driveRight, encoderPort, None)
#pragma config(Motor,  port10,          RightRearMotorA, tmotorVex393_HBridge, openLoop, driveRight, encoderPort, None)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//
#pragma platform(VEX)
/*!!Code automatically generated by 'ROBOTC' configuration wizard               !!
VEX Robotics Source Code, See License (../../LICENSE.TXT)*/
//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(60)
#pragma userControlDuration(0)
#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!

//c 12.987
//Dia = 4.134
//392.3
//on 60 power, 1 rotation of the wheel = 392.3 tics
//one rotation = 12.987 inches
//tics for 4ft move 2100

void pre_auton(){
	//Don't change the below line of code
  bStopTasksBetweenModes = true;
  //If needed, insert preaction code (clearing sensors, etc..) below this comment
}

task autonomous(){
	const int POWAH = 60; //60, do not change
//Move 4ft backwards
	//LeftRearMotorA is Master for Arm
	nMotorEncoder[LeftRearMotorD] = 0;
	motor[LeftRearMotorD] = POWAH;
	motor[RightRearMotorD] = POWAH;
	motor[LeftForwardMotorD] = POWAH;
	motor[RightForwardMotorD] = POWAH;
	while(nMotorEncoder[LeftRearMotorD] >= -2100){
		//foo
	}
	motor[LeftRearMotorD] = 0;
	motor[RightRearMotorD] = 0;
	motor[LeftForwardMotorD] = 0;
	motor[RightForwardMotorD] = 0;
	//Arm
	const unsigned int POWAH2 = 60; //60
	motor[RightForwardMotorA] = POWAH2;
	motor[RightRearMotorA] = POWAH2;
	motor[RightMiddleMotorA] = POWAH2;
	motor[LeftForwardMotorA] = POWAH2;
	motor[LeftMiddleMotorA] = POWAH2;
	motor[LeftForwardMotorA] = POWAH2;
	wait1Msec(2800); // <----------------------
	//All motors stop
	motor[LeftRearMotorA] = 0;
	motor[LeftForwardMotorA] = 0;
	motor[LeftMiddleMotorA] = 0;
	motor[RightForwardMotorA] = 0;
	motor[RightMiddleMotorA] = 0;
	motor[RightRearMotorA] = 0;
}

task usercontrol()
{
	//No user control code needed except the lines of code below this comment
/*
	while (true)
	{
	  UserControlCodePlaceholderForTesting();
	}
	*/
}
