#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, dgtl1,  override,       sensorTouch)
#pragma config(Sensor, I2C_1,  encoder_RDrive, sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Sensor, I2C_2,  encoder_RArm,   sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Sensor, I2C_3,  encoder_LArm,   sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Sensor, I2C_4,  encoder_LDrive, sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Sensor, I2C_5,  encoder_LBucket, sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Sensor, I2C_6,  encoder_RBucket, sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Motor,  port1,           LDrive,        tmotorVex393_HBridge, PIDControl, encoderPort, I2C_4)
#pragma config(Motor,  port2,           LArm,          tmotorVex393_MC29, PIDControl, encoderPort, I2C_3)
#pragma config(Motor,  port3,           RArm,          tmotorVex393_MC29, PIDControl, reversed, encoderPort, I2C_2)
#pragma config(Motor,  port4,           LBucket,       tmotorVex269_MC29, PIDControl, encoderPort, I2C_5)
#pragma config(Motor,  port5,           RBucket,       tmotorVex269_MC29, PIDControl, reversed, encoderPort, I2C_6)
#pragma config(Motor,  port6,           LPaddle,       tmotorVex269_MC29, openLoop)
#pragma config(Motor,  port7,           RPaddle,       tmotorVex269_MC29, openLoop, reversed)
#pragma config(Motor,  port10,          RDrive,        tmotorVex393_HBridge, PIDControl, reversed, encoderPort, I2C_1)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

//////////////////////////////////////////
#pragma platform(VEX)										//
#pragma competitionControl(Competition) //
#pragma autonomousDuration(20)					//	<--------Main Competition Code
#pragma userControlDuration(120)				//						 !!DO NOT MODIFY!!
#include "Vex_Competition_Includes.c" 	//
//////////////////////////////////////////

int aselect = 0; 																	//Autonomous Switch Variable
const int leftButton = 1;
const int centerButton = 2;
const int rightButton = 4;
string mainBattery, backupBattery;
void pre_auton()
{
  bStopTasksBetweenModes = true; 										//Set bStopTasksBetweenModes to false to keep user created tasks running
  																									//between Autonomous and Tele-Op modes. Will need to manage all user
																										//created tasks if set to false.
  nMotorEncoder[RDrive] = 0;
  nMotorEncoder[RArm] = 0;
  nMotorEncoder[LArm] = 0;
  nMotorEncoder[LDrive] = 0;
  nMotorEncoder[LBucket] = 0;
  nMotorEncoder[RBucket] = 0;
  slaveMotor(RBucket, LBucket);
	slaveMotor(RArm, LArm);

  bLCDBacklight = true;
  clearLCDLine(0);
  clearLCDLine(1);
  displayLCDString(0, 0, "Primary: ");
	sprintf(mainBattery, "%1.2f%c", nImmediateBatteryLevel/1000.0,'V');
	displayNextLCDString(mainBattery);
	displayLCDString(1, 0, "Backup: ");
	sprintf(backupBattery, "%1.2f%c", BackupBatteryLevel/1000.0, 'V');
	displayNextLCDString(backupBattery);
	sleep(2000);
																										//$Autonomous Program Selection$
	clearLCDLine(0);
  clearLCDLine(1);
	displayLCDPos(0,0);
	displayNextLCDString("Autonomous ");
	displayLCDPos(0,11);
	displayNextLCDNumber(aselect);
	displayLCDCenteredString(1,"<      X     >");
	while(nLCDButtons!=centerButton)
	{
		if(nLCDButtons==rightButton)
		{
			aselect++;
			clearLCDLine(0);
			displayLCDPos(0,0);
			displayNextLCDString("Autonomous ");
			displayLCDPos(0,11);
			displayNextLCDNumber(aselect);
			while(nLCDButtons==rightButton){}
		}
		else if(nLCDButtons==leftButton)
		{
			clearLCDLine(0);
			displayLCDPos(0,0);
			displayNextLCDString("Autonomous ");
			aselect--;
			displayLCDPos(0,11);
			displayNextLCDNumber(aselect);
			while(nLCDButtons==leftButton){}
		}
	}
	clearLCDLine(1);
	displayLCDCenteredString(1,"Selected");
	sleep(2000);

	clearLCDLine(0);
  clearLCDLine(1);
  displayLCDString(0, 0, "Primary: ");
	displayNextLCDString(mainBattery);
	displayLCDString(1, 0, "Backup: ");
	displayNextLCDString(backupBattery);
	sleep(2000);
	bLCDBacklight = false;
}
																											//$$End Autonomous Selection$$
task autonomous()
{
	reset:
	switch(aselect)
	{
		case 0:
			AutonomousCodePlaceholderForTesting();						//remove pesky compiler warnings
		break;

		case 1:
			UserControlCodePlaceholderForTesting();						//remove pesky compiler warnings
		break;

		default:
			aselect = 0;
			goto reset;
		break;
	}
}

task usercontrol()
{
	const int ths = 15; 															//Threshold Variable
	int c1 = 0, c2 = 0, c3 = 0, c4 = 0;								//Deadzone Variables
	while(true) 																			//Infinite Loop
	{
																										//$Calculate Deadzones$
		if(abs(vexRT[Ch1]) > ths) 												//1 Axis
			c1 = vexRT[Ch1];
		else
			c1 = 0;
		if(abs(vexRT[Ch2]) > ths) 												//2 Axis
			c2 = vexRT[Ch2];
		else
			c2 = 0;
		if(abs(vexRT[Ch3]) > ths) 												//3 Axis
			c3 = vexRT[Ch3];
		else
			c3 = 0;
		if(abs(vexRT[Ch4]) > ths) 												//4 Axis
			c4 = vexRT[Ch4];
		else
			c4 = 0;
																										//$$End Deadzones$$

																										//$Controller Assignments$
		motor[LDrive] = c3 + c4;
		motor[RDrive] = c3 - c4;
    motor[LBucket] = c2;
		if(vexRT[Btn5D]==1)
			motor[LArm] = -100;
		else if(vexRT[Btn5U]==1)
			motor[LArm] = 100;
		else
			motor[LArm] = 0;

		if(vexRT[Btn6D]==1)
		{
			motor[LPaddle] = 127;
			motor[RPaddle] = 127;
		}
		else if(vexRT[Btn6U]==1)
		{
			motor[LPaddle] = -127;
			motor[RPaddle] = -127;
		}
		else
		{
			motor[LPaddle] = 0;
			motor[RPaddle] = 0;
		}
			//Drive
/*			if (vexRT[Ch3] != 0 && abs(vexRT[Ch4]) < 70){ 	//If the left thumb stick is pushed up and not even close to left or right
			motor[LDrive] = vexRT[Ch3];
			motor[RDrive] = vexRT[Ch3];
		}
			if (vexRT[Ch4] != 0){
				if (vexRT[Ch4] == 100){
					motor[LDrive] = -50;
					motor[RDrive] = 50;
			}
				else if (vexRT[Ch4] == -100){
					motor[LDrive] = 50;
					motor[RDrive] = -50;
				}
		}
			if (vexRT[Ch2] != 0){
				motor[LBucket] = vexRT[Ch2];
				motor[RBucket] = vexRT[Ch2];
		}*/

																										//$$End Assignments$$

	} //Infinite loop
}		//End of driver control
