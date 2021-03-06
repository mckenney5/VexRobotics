#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, dgtl3,  TouchSensor,    sensorTouch)
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
#pragma autonomousDuration(45)
#pragma userControlDuration(75)
#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!

//Vars
const int THRESHOLD = 20; //Threshold Variable

void pre_auton(){
	//Don't change the below line of code
	bStopTasksBetweenModes = true;
	//If needed, insert preaction code (clearing sensors, etc..) below this comment
}
task autonomous(){
	const int POWAH = -60; //-60, do not change
//Move 4ft backwards
	motor[LeftRearMotorD] = POWAH;
	motor[RightRearMotorD] = POWAH;
	motor[LeftForwardMotorD] = POWAH;
	motor[RightForwardMotorD] = POWAH;
	nMotorEncoder[LeftRearMotorD] = 0;
	//Drive
	int i = 0;
	while(SensorValue(TouchSensor) == 0 && i < 3000){
		//foo
		wait1Msec(10);
		i++;
	}
	motor[LeftRearMotorD] = 0;
	motor[RightRearMotorD] = 0;
	motor[LeftForwardMotorD] = 0;
	motor[RightForwardMotorD] = 0;
	//Arm
	const unsigned int POWAH2 = 50; //60
	motor[RightForwardMotorA] = POWAH2;
	motor[RightRearMotorA] = POWAH2;
	motor[RightMiddleMotorA] = POWAH2;
	motor[LeftForwardMotorA] = POWAH2;
	motor[LeftMiddleMotorA] = POWAH2;
	motor[LeftForwardMotorA] = POWAH2;
	wait1Msec(4750); // <----------------------
	//All motors stop
	motor[LeftRearMotorA] = 0;
	motor[LeftForwardMotorA] = 0;
	motor[LeftMiddleMotorA] = 0;
	motor[RightForwardMotorA] = 0;
	motor[RightMiddleMotorA] = 0;
	motor[RightRearMotorA] = 0;

}

task usercontrol(){
	int c2X = 0, c2 = 0, c3 = 0, c3X = 0;	//Deadzone Variables
	while(true)
	{
		//All Motor Stop
		//Masters
		if (vexRT[Btn8D] == 1 || vexRT[Btn8DXmtr2]){
			motor[LeftRearMotorD] = 0;
			motor[RightRearMotorD] = 0;
			motor[LeftRearMotorA] = 0;
			//Drive
			motor[LeftForwardMotorD] = 0;
			motor[RightForwardMotorD] = 0;
			//Arm
			motor[LeftForwardMotorA] = 0;
			motor[LeftMiddleMotorA] = 0;
			motor[RightForwardMotorA] = 0;
			motor[RightMiddleMotorA] = 0;
			motor[RightRearMotorA] = 0;
			//wait1Msec(5000); //wait 5 sec
		}
		while(vexRT[Btn6U] == 1){
			motor[RightForwardMotorD] = -200;
			motor[RightRearMotorD] = -200;
			motor[LeftForwardMotorD] = -200;
			motor[LeftRearMotorD] = -200;
		}

		//Slave Mapping
		//LeftRearMotorD is Master for LDriver
		//RightRearMotorD is master for RDriver
		motor[RightForwardMotorD] = motor[RightRearMotorD];
		motor[LeftForwardMotorD] = motor[LeftRearMotorD];

		//LeftRearMotorA is Master for Arm
		motor[RightForwardMotorA] = motor[LeftRearMotorA];
		motor[RightRearMotorA] = motor[LeftRearMotorA];
		motor[RightMiddleMotorA] = motor[LeftRearMotorA];
		motor[LeftForwardMotorA] = motor[LeftRearMotorA];
		motor[LeftMiddleMotorA] = motor[LeftRearMotorA];
		//End Slave

		//User Input
		//Driver
		motor[LeftRearMotorD] = (vexRT[Ch2] + vexRT[Ch1])/2; //(y+x)/2
		motor[RightRearMotorD] = (vexRT[Ch2] - vexRT[Ch1])/2; //(y-x)/2
		//Arm
		int gov = 0; //Govenor
		//Gross Motor Control
		if(abs(vexRT[Ch3Xmtr2]) > THRESHOLD) //3X Axis
			c3X = vexRT[Ch3Xmtr2];
		else
			c3X = 0;
		//Fine Motor Control
		if(abs(vexRT[Ch2Xmtr2]) > THRESHOLD) //2X Axis
			c2X = vexRT[Ch2Xmtr2];
		else
			c2X = 0;
		//Arm Control
		if(abs(c2X) > 0){
			gov = (c2X / 3);
			motor[LeftRearMotorA] = gov;
		}else if(abs(c3X) > 0){
			gov = (c3X / 2);
			motor[LeftRearMotorA] = gov;
		}


	}
}
