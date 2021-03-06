#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, dgtl1,  DArmEncoders,   sensorTouch)
#pragma config(Sensor, dgtl2,  DWheelEncoders, sensorTouch)
#pragma config(Sensor, I2C_1,  encoder_RDrive, sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Sensor, I2C_2,  encoder_LDrive, sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Sensor, I2C_3,  encoder_LArm,   sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Sensor, I2C_4,  encoder_RArm,   sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Sensor, I2C_5,  encoder_Bucket, sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Motor,  port1,           LDrive,        tmotorVex393_HBridge, PIDControl, encoderPort, I2C_2)
#pragma config(Motor,  port3,           RArm,          tmotorVex393_MC29, PIDControl, reversed, encoderPort, I2C_4)
#pragma config(Motor,  port4,           Bucket,        tmotorVex393_MC29, PIDControl, encoderPort, I2C_5)
#pragma config(Motor,  port5,           LPaddle,       tmotorVex269_MC29, openLoop)
#pragma config(Motor,  port6,           RPaddle,       tmotorVex269_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           LArm,          tmotorVex393_MC29, PIDControl, encoderPort, I2C_3)
#pragma config(Motor,  port10,          RDrive,        tmotorVex393_HBridge, PIDControl, reversed, encoderPort, I2C_1)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

//////////////////////////////////////////
#pragma platform(VEX)										//
#pragma competitionControl(Competition) //
#pragma autonomousDuration(20)					//	<--------Main Competition Code
#pragma userControlDuration(120)				//						 !!DO NOT MODIFY!!
#include "Vex_Competition_Includes.c" 	//
//////////////////////////////////////////

int aselect = 0; //Autonomous Switch Variable
const int noButton = 0,leftButton = 1,centerButton = 2,rightButton = 4;	//lcd button variables
string mainBattery, backupBattery;	//battery display strings
const int ths = 15; //Threshold Variable
int c1 = 0, c2 = 0, c3 = 0, c4 = 0;	//Deadzone Variables
string ProgramName = "Rear Red ";	//lcd string

task ArmEncoders()
{
	while (true)
	{
		clearLCDLine(0);
 		clearLCDLine(1);
  	displayLCDPos(0,0);
  	displayNextLCDString("LArm = ");
  	displayNextLCDNumber(nMotorEncoder[LArm]);	//LArm encoder readout
 		displayLCDPos(1,0);
  	displayNextLCDString("RArm = ");
  	displayNextLCDNumber(nMotorEncoder[RArm]);	//RArm encoder readout
  	if(vexRT[Btn7D] == 1)	//reset encoders
 		{
 		 	nMotorEncoder[LArm] = 0;
 		 	nMotorEncoder[RArm] = 0;
 		}
	}
}
task WheelEncoders()
{
	while (true)
	{
		clearLCDLine(0);
  	clearLCDLine(1);
  	displayLCDPos(0,0);
  	displayNextLCDString("LDrive = ");
  	displayNextLCDNumber(nMotorEncoder[LDrive]);	//LDrive encoder readout
  	displayLCDPos(1,0);
  	displayNextLCDString("RDrive = ");
  	displayNextLCDNumber(nMotorEncoder[RDrive]);	//RDrive encoder readout
  	if(vexRT[Btn7D] == 1)	//reset encoders
 		{
 	 		nMotorEncoder[LDrive] = 0;
 	 		nMotorEncoder[RDrive] = 0;
 		}
	}
}
void pre_auton()
{
  bStopTasksBetweenModes = true; 	//Set bStopTasksBetweenModes to false to keep user created tasks running
  																//between Autonomous and Tele-Op modes. Will need to manage all user
																	//created tasks if set to false.
  nMotorEncoder[RDrive] = 0;
  nMotorEncoder[RArm] = 0;
  nMotorEncoder[LArm] = 0;
  nMotorEncoder[LDrive] = 0;
  nMotorEncoder[Bucket] = 0;

	top:	//hot restart point

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
	displayNextLCDString(ProgramName);
	displayNextLCDNumber(aselect);
	displayLCDCenteredString(1,"<      X     >");
	clearTimer(T1);
	while(nLCDButtons!=centerButton && time1[T1]<5000)
	{	//5 second time limit for program selection
		if(nLCDButtons==rightButton)
		{
			clearTimer(T1);	//reset time limit
			aselect++;	//go to next auto program

			if (aselect == 0) ProgramName = "Rear Red ";	//build name to be displayed
			else if (aselect == 1) ProgramName = "Front Red ";
			else if (aselect == 2) ProgramName = "Rear Blue ";
			else if (aselect == 3) ProgramName = "Front Blue ";
			else if (aselect == 4) ProgramName = "Drive Test ";
			else ProgramName = "Default ";

			clearLCDLine(0);
			displayLCDPos(0,0);
			displayNextLCDString(ProgramName);	//display name
			displayNextLCDNumber(aselect);	//display number
			while(nLCDButtons!=noButton){}	//wait for button release
		}
		else if(nLCDButtons==leftButton)
		{
			clearTimer(T1);	//reset time limit
			aselect--;	//go to previous auto program

			if (aselect == 0) ProgramName = "Rear Red ";	//build name to be displayed
			else if (aselect == 1) ProgramName = "Front Red ";
			else if (aselect == 2) ProgramName = "Rear Blue ";
			else if (aselect == 3) ProgramName = "Front Blue ";
			else if (aselect == 4) ProgramName = "Drive Test ";
			else ProgramName = "Default ";

			clearLCDLine(0);
			displayLCDPos(0,0);
			displayNextLCDString(ProgramName);	//display name
			displayNextLCDNumber(aselect);	//display number
			while(nLCDButtons!=noButton){}	//wait for button release
		}
	}
	clearLCDLine(1);
	displayLCDCenteredString(1,"Selected");
	sleep(2000);
	if(nLCDButtons!=0)	//if any buttons pressed
	{
		while(nLCDButtons!=noButton){}	//wait for release
		goto top;	//hot restart program
	}
																										//$$End Autonomous Selection$$
	clearLCDLine(0);
  clearLCDLine(1);
  displayLCDString(0, 0, "Primary: ");
	sprintf(mainBattery, "%1.2f%c", nImmediateBatteryLevel/1000.0,'V');
	displayNextLCDString(mainBattery);
	displayLCDString(1, 0, "Backup: ");
	sprintf(backupBattery, "%1.2f%c", BackupBatteryLevel/1000.0, 'V');
	displayNextLCDString(backupBattery);
	sleep(2000);
	if(nLCDButtons!=noButton)	//if any buttons pressed
	{
		while(nLCDButtons!=noButton){}	//wait for release
		goto top;	//hot restart program
	}
	bLCDBacklight = false;
}
task autonomous()
{
	clearTimer(T2);	//start autonomous timer
	reset:
	switch(aselect)
	{
		case 0:	//rear left/red starting tile
			moveMotorTarget(LArm,1800,100,false);	//raise arm to hit large balls
			moveMotorTarget(RArm,1800,100,false);

			moveMotorTarget(LDrive,4356,100,true);	//drive forward from start over bump
			moveMotorTarget(RDrive,4356,100,true);

			while(getMotorTargetCompleted(LDrive)!=1){}	//wait for drive completion
			while(getMotorTargetCompleted(RDrive)!=1){}
			while(getMotorTargetCompleted(LArm)!=1){}	//wait for arm completion
			while(getMotorTargetCompleted(RArm)!=1){}

			moveMotorTarget(LDrive,871,100,true);	//drive forward and hit large ball 1
			moveMotorTarget(RDrive,871,100,true);

			while(getMotorTargetCompleted(LDrive)!=1){}	//wait for drive completion
			while(getMotorTargetCompleted(RDrive)!=1){}

			moveMotorTarget(LDrive,871,100,true);	//back up to previous values
			moveMotorTarget(RDrive,871,100,true);

			while(getMotorTargetCompleted(LDrive)!=1){}	//wait for drive completion
			while(getMotorTargetCompleted(RDrive)!=1){}

			moveMotorTarget(LDrive,314,100,true);	//turn right 90 degrees
			moveMotorTarget(RDrive,-314,100,true);

			while(getMotorTargetCompleted(LDrive)!=1){}	//wait for turn completion
			while(getMotorTargetCompleted(RDrive)!=1){}

			moveMotorTarget(LDrive,2614,100,true);	//drive forward to line up large ball 2 on left
			moveMotorTarget(RDrive,2614,100,true);

			while(getMotorTargetCompleted(LDrive)!=1){}	//wait for drive completion
			while(getMotorTargetCompleted(RDrive)!=1){}

			moveMotorTarget(LDrive,-314,100,true);	//turn left 90 degrees
			moveMotorTarget(RDrive,314,100,true);

			while(getMotorTargetCompleted(LDrive)!=1){}	//wait for turn completion
			while(getMotorTargetCompleted(RDrive)!=1){}

			moveMotorTarget(LDrive,799,100,true);	//drive forward and hit large ball 2
			moveMotorTarget(RDrive,799,100,true);

			while(getMotorTargetCompleted(LDrive)!=1){}	//wait for drive completion
			while(getMotorTargetCompleted(RDrive)!=1){}

			moveMotorTarget(LDrive,-799,100,true);	//back up to previous values
			moveMotorTarget(RDrive,000,100,true);

			while(getMotorTargetCompleted(LDrive)!=1){}	//wait for drive completion
			while(getMotorTargetCompleted(RDrive)!=1){}

			moveMotorTarget(LArm,0,100,false);	//lower arm to ground
			moveMotorTarget(RArm,0,100,false);

			while(getMotorTargetCompleted(LArm)!=1){}	//wait for arm completion
			while(getMotorTargetCompleted(RArm)!=1){}

			bLCDBacklight = true;
			clearLCDLine(0);
			clearLCDLine(1);
			displayLCDPos(0,0);
			displayNextLCDString(ProgramName);
			displayNextLCDNumber(aselect);
			displayLCDPos(1,0);
			displayNextLCDString("Time: ");
			displayNextLCDNumber(time1[T2]/1000);	//display elapsed time for autonomous period
			while(nLCDButtons!=0){}
			bLCDBacklight = false;
		break;

		case 1:	//front left/red starting tile
			moveMotorTarget(LArm,1800,100,false);	//raise arm to hit large balls
			moveMotorTarget(RArm,1800,100,false);

			moveMotorTarget(LDrive,1525,100,true);	//drive forward from start
			moveMotorTarget(RDrive,1525,100,true);

			while(getMotorTargetCompleted(LDrive)!=1){}	//wait for drive completion
			while(getMotorTargetCompleted(RDrive)!=1){}
			while(getMotorTargetCompleted(LArm)!=1){}	//wait for arm completion
			while(getMotorTargetCompleted(RArm)!=1){}

			moveMotorTarget(LDrive,871,100,true);	//drive forward and hit large ball 1
			moveMotorTarget(RDrive,871,100,true);

			while(getMotorTargetCompleted(LDrive)!=1){}	//wait for drive completion
			while(getMotorTargetCompleted(RDrive)!=1){}

			moveMotorTarget(LDrive,871,100,true);	//back up to previous values
			moveMotorTarget(RDrive,871,100,true);

			while(getMotorTargetCompleted(LDrive)!=1){}	//wait for drive completion
			while(getMotorTargetCompleted(RDrive)!=1){}

			moveMotorTarget(LDrive,314,100,true);	//turn right 90 degrees
			moveMotorTarget(RDrive,-314,100,true);

			while(getMotorTargetCompleted(LDrive)!=1){}	//wait for turn completion
			while(getMotorTargetCompleted(RDrive)!=1){}

			moveMotorTarget(LDrive,2614,100,true);	//drive forward to line up large ball 2 on left
			moveMotorTarget(RDrive,2614,100,true);

			while(getMotorTargetCompleted(LDrive)!=1){}	//wait for drive completion
			while(getMotorTargetCompleted(RDrive)!=1){}

			moveMotorTarget(LDrive,-314,100,true);	//turn left 90 degrees
			moveMotorTarget(RDrive,314,100,true);

			while(getMotorTargetCompleted(LDrive)!=1){}	//wait for turn completion
			while(getMotorTargetCompleted(RDrive)!=1){}

			moveMotorTarget(LDrive,799,100,true);	//drive forward and hit large ball 2
			moveMotorTarget(RDrive,799,100,true);

			while(getMotorTargetCompleted(LDrive)!=1){}	//wait for drive completion
			while(getMotorTargetCompleted(RDrive)!=1){}

			moveMotorTarget(LDrive,-799,100,true);	//back up to previous values
			moveMotorTarget(RDrive,-799,100,true);

			while(getMotorTargetCompleted(LDrive)!=1){}	//wait for drive completion
			while(getMotorTargetCompleted(RDrive)!=1){}

			moveMotorTarget(LArm,0,100,false);	//lower arm to ground
			moveMotorTarget(RArm,0,100,false);

			while(getMotorTargetCompleted(LArm)!=1){}	//wait for arm completion
			while(getMotorTargetCompleted(RArm)!=1){}

			bLCDBacklight = true;
			clearLCDLine(0);
			clearLCDLine(1);
			displayLCDPos(0,0);
			displayNextLCDString(ProgramName);
			displayNextLCDNumber(aselect);
			displayLCDPos(1,0);
			displayNextLCDString("Time: ");
			displayNextLCDNumber(time1[T2]/1000);	//display elapsed time for autonomous period
			while(nLCDButtons!=0){}
			bLCDBacklight = false;
		break;

		case 2:	//rear right/blue starting tile
			moveMotorTarget(LArm,1800,100,false);	//raise arm to hit large balls
			moveMotorTarget(RArm,1800,100,false);

			moveMotorTarget(LDrive,4356,100,true);	//drive forward from start over bump
			moveMotorTarget(RDrive,4356,100,true);

			while(getMotorTargetCompleted(LDrive)!=1){}	//wait for drive completion
			while(getMotorTargetCompleted(RDrive)!=1){}
			while(getMotorTargetCompleted(LArm)!=1){}	//wait for arm completion
			while(getMotorTargetCompleted(RArm)!=1){}

			moveMotorTarget(LDrive,871,100,true);	//drive forward and hit large ball 1
			moveMotorTarget(RDrive,871,100,true);

			while(getMotorTargetCompleted(LDrive)!=1){}	//wait for drive completion
			while(getMotorTargetCompleted(RDrive)!=1){}

			moveMotorTarget(LDrive,871,100,true);	//back up to previous values
			moveMotorTarget(RDrive,871,100,true);

			while(getMotorTargetCompleted(LDrive)!=1){}	//wait for drive completion
			while(getMotorTargetCompleted(RDrive)!=1){}

			moveMotorTarget(LDrive,-314,100,true);	//turn left 90 degrees
			moveMotorTarget(RDrive,314,100,true);

			while(getMotorTargetCompleted(LDrive)!=1){}	//wait for turn completion
			while(getMotorTargetCompleted(RDrive)!=1){}

			moveMotorTarget(LDrive,2614,100,true);	//drive forward to line up large ball 2 on right
			moveMotorTarget(RDrive,2614,100,true);

			while(getMotorTargetCompleted(LDrive)!=1){}	//wait for drive completion
			while(getMotorTargetCompleted(RDrive)!=1){}

			moveMotorTarget(LDrive,314,100,true);	//turn right 90 degrees
			moveMotorTarget(RDrive,-314,100,true);

			while(getMotorTargetCompleted(LDrive)!=1){}	//wait for turn completion
			while(getMotorTargetCompleted(RDrive)!=1){}

			moveMotorTarget(LDrive,799,100,true);	//drive forward and hit large ball 2
			moveMotorTarget(RDrive,799,100,true);

			while(getMotorTargetCompleted(LDrive)!=1){}	//wait for drive completion
			while(getMotorTargetCompleted(RDrive)!=1){}

			moveMotorTarget(LDrive,-799,100,true);	//back up to previous values
			moveMotorTarget(RDrive,000,100,true);

			while(getMotorTargetCompleted(LDrive)!=1){}	//wait for drive completion
			while(getMotorTargetCompleted(RDrive)!=1){}

			moveMotorTarget(LArm,0,100,false);	//lower arm to ground
			moveMotorTarget(RArm,0,100,false);

			while(getMotorTargetCompleted(LArm)!=1){}	//wait for arm completion
			while(getMotorTargetCompleted(RArm)!=1){}

			bLCDBacklight = true;
			clearLCDLine(0);
			clearLCDLine(1);
			displayLCDPos(0,0);
			displayNextLCDString(ProgramName);
			displayNextLCDNumber(aselect);
			displayLCDPos(1,0);
			displayNextLCDString("Time: ");
			displayNextLCDNumber(time1[T2]/1000);	//display elapsed time for autonomous period
			while(nLCDButtons!=0){}
			bLCDBacklight = false;
		break;

		case 3:	//front right/blue starting tile
			moveMotorTarget(LArm,1800,100,false);	//raise arm to hit large balls
			moveMotorTarget(RArm,1800,100,false);

			moveMotorTarget(LDrive,1525,100,true);	//drive forward from start over bump
			moveMotorTarget(RDrive,1525,100,true);

			while(getMotorTargetCompleted(LDrive)!=1){}	//wait for drive completion
			while(getMotorTargetCompleted(RDrive)!=1){}
			while(getMotorTargetCompleted(LArm)!=1){}	//wait for arm completion
			while(getMotorTargetCompleted(RArm)!=1){}

			moveMotorTarget(LDrive,871,100,true);	//drive forward and hit large ball 1
			moveMotorTarget(RDrive,871,100,true);

			while(getMotorTargetCompleted(LDrive)!=1){}	//wait for drive completion
			while(getMotorTargetCompleted(RDrive)!=1){}

			moveMotorTarget(LDrive,871,100,true);	//back up to previous values
			moveMotorTarget(RDrive,871,100,true);

			while(getMotorTargetCompleted(LDrive)!=1){}	//wait for drive completion
			while(getMotorTargetCompleted(RDrive)!=1){}

			moveMotorTarget(LDrive,-314,100,true);	//turn left 90 degrees
			moveMotorTarget(RDrive,314,100,true);

			while(getMotorTargetCompleted(LDrive)!=1){}	//wait for turn completion
			while(getMotorTargetCompleted(RDrive)!=1){}

			moveMotorTarget(LDrive,2614,100,true);	//drive forward to line up large ball 2 on right
			moveMotorTarget(RDrive,2614,100,true);

			while(getMotorTargetCompleted(LDrive)!=1){}	//wait for drive completion
			while(getMotorTargetCompleted(RDrive)!=1){}

			moveMotorTarget(LDrive,314,100,true);	//turn right 90 degrees
			moveMotorTarget(RDrive,-314,100,true);

			while(getMotorTargetCompleted(LDrive)!=1){}	//wait for turn completion
			while(getMotorTargetCompleted(RDrive)!=1){}

			moveMotorTarget(LDrive,799,100,true);	//drive forward and hit large ball 2
			moveMotorTarget(RDrive,799,100,true);

			while(getMotorTargetCompleted(LDrive)!=1){}	//wait for drive completion
			while(getMotorTargetCompleted(RDrive)!=1){}

			moveMotorTarget(LDrive,-799,100,true);	//back up to previous values
			moveMotorTarget(RDrive,000,100,true);

			while(getMotorTargetCompleted(LDrive)!=1){}	//wait for drive completion
			while(getMotorTargetCompleted(RDrive)!=1){}

			moveMotorTarget(LArm,0,100,false);	//lower arm to ground
			moveMotorTarget(RArm,0,100,false);

			while(getMotorTargetCompleted(LArm)!=1){}	//wait for arm completion
			while(getMotorTargetCompleted(RArm)!=1){}

			bLCDBacklight = true;
			clearLCDLine(0);
			clearLCDLine(1);
			displayLCDPos(0,0);
			displayNextLCDString(ProgramName);
			displayNextLCDNumber(aselect);
			displayLCDPos(1,0);
			displayNextLCDString("Time: ");
			displayNextLCDNumber(time1[T2]/1000);	//display elapsed time for autonomous period
			while(nLCDButtons!=0){}
			bLCDBacklight = false;
		break;

		case 4:
			clearLCDLine(0);
			clearLCDLine(1);
			displayLCDPos(0,0);
			displayNextLCDString("Moving bot 2ft!");
			displayLCDCenteredString(1,"4");
			moveMotorTarget(LDrive,1742,100,true);	//drive forward at the new encoder rate
			moveMotorTarget(RDrive,1742,100,true);
			while(getMotorTargetCompleted(LDrive)!=1){}	//wait for drive completion
			while(getMotorTargetCompleted(RDrive)!=1){}
		break;

		case 5:
			clearLCDLine(0);
			clearLCDLine(1);
			displayLCDPos(0,0);
			displayNextLCDString("Moving bot 2ft!");
			displayLCDCenteredString(1,"5");
			setMotorTarget(LDrive,1742,100,true);	//forward
			setMotorTarget(RDrive,1742,100,true);	//forward
			while(getMotorTargetCompleted(LDrive)!=1){}	//wait for drive completion
			while(getMotorTargetCompleted(RDrive)!=1){}
		break;

		default:
			bLCDBacklight = true;
			aselect = 0;
			clearLCDLine(0);
			clearLCDLine(1);
			displayLCDPos(0,0);
			displayNextLCDString(ProgramName);
			displayNextLCDNumber(aselect);
			displayLCDCenteredString(1,"Running as Default");
			goto reset;	//restart autonomous segment
			UserControlCodePlaceholderForTesting();	//remove pesky compiler warnings, this line will never run
			AutonomousCodePlaceholderForTesting();	//remove pesky compiler warnings, this line will never run
		break;
	}
}	//end of autonomous

task usercontrol()
{
	if(SensorValue(DArmEncoders)==1)	//if jumper is in port 1
		startTask(ArmEncoders);
	else if(SensorValue(DWheelEncoders)==1)	//if jumper is in port 2
		startTask(WheelEncoders);
	while(true)	//Infinite Loop
	{
																										//$Calculate Deadzones$
		if(abs(vexRT[Ch1]) > ths) //1 Axis
			c1 = vexRT[Ch1];
		else
			c1 = 0;
		if(abs(vexRT[Ch2]) > ths) //2 Axis
			c2 = vexRT[Ch2];
		else
			c2 = 0;
		if(abs(vexRT[Ch3]) > ths) //3 Axis
			c3 = vexRT[Ch3];
		else
			c3 = 0;
		if(abs(vexRT[Ch4]) > ths) //4 Axis
			c4 = vexRT[Ch4];
		else
			c4 = 0;
																										//$$End Deadzones$$

																										//$Controller Assignments$
		motor[LDrive] = c3 + c4;	//drive axis
		motor[RDrive] = c3 - c4;	//turn axis
		if(c2>100)
			motor[Bucket] = c2;
		else
			motor[Bucket] = c2/4;	//bucket axis
    motor[LPaddle] = c1;	//paddle axit !BETA!
    motor[RPaddle] = c1;

    //setMotorTarget(RArm,nMotorEncoder[LArm],120,true);

		if(vexRT[Btn5D]==1)	//arms down
		{
			motor[LArm] = -120;
			motor[RArm] = -120;
		}
		else if(vexRT[Btn5U]==1)	//arms up
		{
			motor[LArm] = 120;
			motor[RArm] = 120;
		}
		else
		{
			motor[LArm] = 0;
			motor[RArm] = 0;
		}
		if(vexRT[Btn6D]==1)	//paddles forward
		{
			motor[LPaddle] = 127;
			motor[RPaddle] = 127;
		}
		else if(vexRT[Btn6U]==1)	//paddles reverse
		{
			motor[LPaddle] = -127;
			motor[RPaddle] = -127;
		}
		else
		{
			motor[LPaddle] = 0;
			motor[RPaddle] = 0;
		}
																										//$$End Assignments$$
	} //Infinite loop
}	//End of driver control
