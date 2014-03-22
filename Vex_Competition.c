#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, dgtl1,  override,       sensorTouch)
#pragma config(Sensor, I2C_1,  encoder_rdrive, sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Sensor, I2C_2,  encoder_rarm,   sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Sensor, I2C_3,  encoder_larm,   sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Sensor, I2C_4,  encoder_ldrive, sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Sensor, I2C_5,  encoder_lbucket, sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Sensor, I2C_6,  encoder_rbucket, sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Motor,  port1,           t269,          tmotorVex269_HBridge, openLoop)
#pragma config(Motor,  port2,           rdrive,        tmotorVex393_MC29, PIDControl, encoderPort, I2C_1)
#pragma config(Motor,  port3,           rarm,          tmotorVex393_MC29, PIDControl, encoderPort, I2C_2)
#pragma config(Motor,  port4,           larm,          tmotorVex393_MC29, PIDControl, encoderPort, I2C_3)
#pragma config(Motor,  port5,           ldrive,        tmotorVex393_MC29, PIDControl, encoderPort, I2C_4)
#pragma config(Motor,  port6,           lbucket,       tmotorVex393_MC29, PIDControl, encoderPort, I2C_5)
#pragma config(Motor,  port7,           rbucket,       tmotorVex393_MC29, PIDControl, encoderPort, I2C_6)
#pragma config(Motor,  port8,           lpaddle,       tmotorVex269_MC29, openLoop)
#pragma config(Motor,  port9,           rpaddle,       tmotorVex269_MC29, openLoop)
#pragma config(Motor,  port10,          t393,          tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

//////////////////////////////////////////
#pragma platform(VEX)										//
#pragma competitionControl(Competition) //
#pragma autonomousDuration(20)					//	<--------Main Competition Code
#pragma userControlDuration(120)				//						 !!DO NOT MODIFY!!
#include "Vex_Competition_Includes.c" 	//
//////////////////////////////////////////

short aselect = 0; //----------------------------------Autonomous Switch Variable
const short leftButton = 1;
const short centerButton = 2;
const short rightButton = 4;
string mainBattery, backupBattery;
void pre_auton()
{
  bStopTasksBetweenModes = true; //------------------Set bStopTasksBetweenModes to false to keep user created tasks running
  																									 //between Autonomous and Tele-Op modes. Will need to manage all user
  																									 //created tasks if set to false.
  nMotorEncoder[rdrive] = 0;
  nMotorEncoder[rarm] = 0;
  nMotorEncoder[larm] = 0;
  nMotorEncoder[ldrive] = 0;
  nMotorEncoder[lbucket] = 0;
  nMotorEncoder[rbucket] = 0;

  //-------------------------------------------------$Autonomous Program Selection$
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

	clearLCDLine(0);
  clearLCDLine(1);
	displayLCDPos(0,0);
	displayNextLCDString("Autonomous ");
	displayLCDPos(0,11);
	displayNextLCDNumber(aselect);
	displayLCDCenteredString(1,"<     X     >");
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
			while(nLCDButtons==rightButton)
			{}
		}
		else if(nLCDButtons==leftButton)
		{
			clearLCDLine(0);
			displayLCDPos(0,0);
			displayNextLCDString("Autonomous ");
			aselect--;
			displayLCDPos(0,11);
			displayNextLCDNumber(aselect);
			while(nLCDButtons==leftButton)
			{}
		}
	}
 	//-------------------------------------------------$$End Autonomous Selection$$
	clearLCDLine(1);
	displayLCDCenteredString(1,"Selected");
	sleep(2000);
	bLCDBacklight = false;
}
task autonomous()
{
	reset:
	switch(aselect)
	{
		case 0:
			clearLCDLine(0);
			displayLCDCenteredString(0,"pgm0 WORKING");
		break;

		case 1:
			clearLCDLine(1);
			displayLCDCenteredString(1,"pgm1 WORKING");
		break;

		default:
			aselect = 0;
			goto reset;
		break;
	}
//AutonomousCodePlaceholderForTesting(); //----------Interface With Debugger
}

task usercontrol()
{
	const short ths = 15; //---------------------------Threshold Variable
	short c1 = 0, c2 = 0, c3 = 0, c4 = 0;	//-----------Deadzone Variables
	while(true) //-------------------------------------Infinite Loop
	{
	//-------------------------------------------------$Calculate Deadzones$
		if(abs(vexRT[Ch1]) > ths) //------------------------1 Axis
			c1 = vexRT[Ch1];
		else
			c1 = 0;
		if(abs(vexRT[Ch2]) > ths) //------------------------2 Axis
			c2 = vexRT[Ch2];
		else
			c2 = 0;
		if(abs(vexRT[Ch3]) > ths) //------------------------3 Axis
			c3 = vexRT[Ch3];
		else
			c3 = 0;
		if(abs(vexRT[Ch4]) > ths) //------------------------4 Axis
			c4 = vexRT[Ch4];
		else
			c4 = 0;
	//-------------------------------------------------$$End Deadzones$$

	//UserControlCodePlaceholderForTesting(); //-------Interface With Debugger

	//-------------------------------------------------$Controller Assignments$

	//-------------------------------------------------$$End Assignments$$
	}
}
