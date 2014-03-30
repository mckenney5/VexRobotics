#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, dgtl1,  DArmEncoders,   sensorTouch)
#pragma config(Sensor, dgtl2,  DWheelEncoders, sensorTouch)
#pragma config(Sensor, I2C_1,  encoder_RDrive, sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Sensor, I2C_2,  encoder_RArm,   sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Sensor, I2C_3,  encoder_LArm,   sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Sensor, I2C_4,  encoder_LDrive, sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Sensor, I2C_5,  encoder_Bucket, sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Motor,  port1,           LDrive,        tmotorVex393_HBridge, PIDControl, encoderPort, I2C_4)
#pragma config(Motor,  port2,           LArm,          tmotorVex393_MC29, PIDControl, encoderPort, I2C_3)
#pragma config(Motor,  port3,           RArm,          tmotorVex393_MC29, PIDControl, reversed, encoderPort, I2C_2)
#pragma config(Motor,  port4,           Bucket,        tmotorVex393_MC29, PIDControl, encoderPort, I2C_5)
#pragma config(Motor,  port5,           LPaddle,       tmotorVex269_MC29, openLoop)
#pragma config(Motor,  port6,           RPaddle,       tmotorVex269_MC29, openLoop, reversed)
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
const int leftButton = 1,centerButton = 2, rightButton = 4;	//lcd button variables
string mainBattery, backupBattery;	//battery display strings
const int ths = 15; //Threshold Variable
int c1 = 0, c2 = 0, c3 = 0, c4 = 0;	//Deadzone Variables
string ProgramName = "Rear Red";

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

	while(SensorValue(DArmEncoders)==1)	//while jumper in port 1
	{
		clearLCDLine(0);
  	clearLCDLine(1);
  	displayLCDPos(0,0);
  	displayNextLCDString("LArm = ");
  	displayLCDPos(0,7);
  	displayNextLCDNumber(nMotorEncoder[LArm]);	//LArm encoder readout
  	displayLCDPos(1,0);
  	displayNextLCDString("RArm = ");
  	displayLCDPos(1,7);
  	displayNextLCDNumber(nMotorEncoder[RArm]);	//RArm encoder readout
  	if(nLCDButtons==centerButton)
  		goto top;	//if center button pressed, hot restart program
  }
  while(SensorValue(DWheelEncoders)==1)	//while jumper in port 2
	{
		clearLCDLine(0);
  	clearLCDLine(1);
  	displayLCDPos(0,0);
  	displayNextLCDString("LDrive = ");
  	displayLCDPos(0,7);
  	displayNextLCDNumber(nMotorEncoder[LDrive]);	//LDrive encoder readout
  	displayLCDPos(1,0);
  	displayNextLCDString("RDrive = ");
  	displayLCDPos(1,7);
  	displayNextLCDNumber(nMotorEncoder[RDrive]);	//RDrive encoder readout
  	if(nLCDButtons==centerButton)
  		goto top;	//if center button pressed, hot restart program
  }
																										//$Autonomous Program Selection$
	clearLCDLine(0);
  clearLCDLine(1);
	displayLCDPos(0,0);
	displayNextLCDString(ProgramName);
	displayLCDPos(0,11);
	displayNextLCDNumber(aselect);
	displayLCDCenteredString(1,"<      X     >");
	clearTimer(T1);
	while(nLCDButtons!=centerButton && time1[T1]<5000)
	{	//5 second time limit for program selection
		if(nLCDButtons==rightButton)
		{
			clearTimer(T1);	//reset time limit
			aselect++;	//go to next auto program
			clearLCDLine(0);
			displayLCDPos(0,0);
			if (aselect == 0) ProgramName = "Rear Red";
			else if (aselect == 1) ProgramName = "Front Red";
			else if (aselect == 2) ProgramName = "Rear Blue";
			else if (aselect == 3) ProgramName = "Front Blue";
			else if (aselect == 4) ProgramName = "Drive Test";
			else ProgramName = "NONE";
			displayNextLCDString(ProgramName);
			displayLCDPos(0,12);
			displayNextLCDNumber(aselect);
			while(nLCDButtons==rightButton){}
		}
		else if(nLCDButtons==leftButton)
		{
			clearTimer(T1);	//reset time limit
			clearLCDLine(0);
			displayLCDPos(0,0);
			if (aselect == 0) ProgramName = "Rear Red";
			else if (aselect == 1) ProgramName = "Front Red";
			else if (aselect == 2) ProgramName = "Rear Blue";
			else if (aselect == 3) ProgramName = "Front Blue";
			else if (aselect == 4) ProgramName = "Drive Test";
			else ProgramName = "NONE";
			displayNextLCDString(ProgramName);
			aselect--;	//go to previous auto program
			displayLCDPos(0,12);
			displayNextLCDNumber(aselect);
			while(nLCDButtons==leftButton){}
		}
	}
	clearLCDLine(1);
	displayLCDCenteredString(1,"Selected ");
	displayLCDPos(1,9);
	displayLCDCenteredString(1,ProgramName);
	sleep(2000);
	if(nLCDButtons!=0)	//if any buttons pressed
		goto top;	//hot restart program
																										//$$End Autonomous Selection$$
	clearLCDLine(0);
  clearLCDLine(1);
  displayLCDString(0, 0, "Primary: ");
	displayNextLCDString(mainBattery);
	displayLCDString(1, 0, "Backup: ");
	displayNextLCDString(backupBattery);
	sleep(2000);
	if(nLCDButtons!=0)	//if any buttons pressed
		goto top;	//hot restart program
	bLCDBacklight = false;
}
task autonomous()
{
	clearTimer(T2);	//start autonomous timer
	reset:
	switch(aselect)
	{
		case 0:	//rear left starting tile
			moveMotorTarget(LArm,000,100,true);	//raise arm to hit large balls
			moveMotorTarget(RArm,000,100,true);

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

			moveMotorTarget(LArm,000,100,true);	//lower arm to ground
			moveMotorTarget(RArm,000,100,true);

			while(getMotorTargetCompleted(LArm)!=1){}	//wait for arm completion
			while(getMotorTargetCompleted(RArm)!=1){}

			bLCDBacklight = true;
			clearLCDLine(0);
			clearLCDLine(1);
			displayLCDPos(0,0);
			displayNextLCDString("Auto ");
			displayNextLCDNumber(aselect);
			displayNextLCDString("Complete");
			displayLCDPos(1,0);
			displayNextLCDString("Time: ");
			displayNextLCDNumber(time1[T2]/1000);	//display elapsed time for autonomous period
			while(nLCDButtons!=0){}
			bLCDBacklight = false;
		break;

		case 1:	//front left starting tile
			moveMotorTarget(LArm,000,100,true);	//raise arm to hit large balls
			moveMotorTarget(RArm,000,100,true);

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

			moveMotorTarget(LArm,000,100,true);	//lower arm to ground
			moveMotorTarget(RArm,000,100,true);

			while(getMotorTargetCompleted(LArm)!=1){}	//wait for arm completion
			while(getMotorTargetCompleted(RArm)!=1){}

			bLCDBacklight = true;
			clearLCDLine(0);
			clearLCDLine(1);
			displayLCDPos(0,0);
			displayNextLCDString("Auto ");
			displayNextLCDNumber(aselect);
			displayNextLCDString("Complete");
			displayLCDPos(1,0);
			displayNextLCDString("Time: ");
			displayNextLCDNumber(time1[T2]/1000);	//display elapsed time for autonomous period
			while(nLCDButtons!=0){}
			bLCDBacklight = false;
		break;

		case 2:	//rear right starting tile
			moveMotorTarget(LArm,000,100,true);	//raise arm to hit large balls
			moveMotorTarget(RArm,000,100,true);

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

			moveMotorTarget(LArm,000,100,true);	//lower arm to ground
			moveMotorTarget(RArm,000,100,true);

			while(getMotorTargetCompleted(LArm)!=1){}	//wait for arm completion
			while(getMotorTargetCompleted(RArm)!=1){}

			bLCDBacklight = true;
			clearLCDLine(0);
			clearLCDLine(1);
			displayLCDPos(0,0);
			displayNextLCDString("Auto ");
			displayNextLCDNumber(aselect);
			displayNextLCDString("Complete");
			displayLCDPos(1,0);
			displayNextLCDString("Time: ");
			displayNextLCDNumber(time1[T2]/1000);	//display elapsed time for autonomous period
			while(nLCDButtons!=0){}
			bLCDBacklight = false;
		break;

		case 3:	//front right starting tile
			moveMotorTarget(LArm,000,100,true);	//raise arm to hit large balls
			moveMotorTarget(RArm,000,100,true);

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

			moveMotorTarget(LArm,000,100,true);	//lower arm to ground
			moveMotorTarget(RArm,000,100,true);

			while(getMotorTargetCompleted(LArm)!=1){}	//wait for arm completion
			while(getMotorTargetCompleted(RArm)!=1){}

			bLCDBacklight = true;
			clearLCDLine(0);
			clearLCDLine(1);
			displayLCDPos(0,0);
			displayNextLCDString("Auto ");
			displayNextLCDNumber(aselect);
			displayNextLCDString("Complete");
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
			moveMotorTarget(LDrive,1742.3472921053884531850307125,50,true);	//drive forward at the new encoder rate
			moveMotorTarget(RDrive,1742.3472921053884531850307125,50,true);
			while(getMotorTargetCompleted(LDrive)!=1){}	//wait for drive completion
			while(getMotorTargetCompleted(RDrive)!=1){}
		break;

		default:
			bLCDBacklight = true;
			aselect = 0;
			clearLCDLine(0);
			clearLCDLine(1);
			displayLCDPos(0,0);
			displayNextLCDString("Autonomous ");
			displayLCDPos(0,11);
			displayNextLCDNumber(aselect);
			displayLCDCenteredString(1,"Running as Default");
			goto reset;
			UserControlCodePlaceholderForTesting();	//remove pesky compiler warnings
			AutonomousCodePlaceholderForTesting();	//remove pesky compiler warnings
		break;
	}
}	//end of autonomous

task usercontrol()
{
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
    motor[Bucket] = c2/4;	//bucket axis
    motor[LPaddle] = c1;	//paddle axit !BETA!
    motor[RPaddle] = c1;

    //setMotorTarget(RArm,nMotorEncoder[LArm],120,true);

		if(vexRT[Btn5D]==1)	//arms down
		{
			motor[LArm] = -120;
			motor[RArm] = -100;
		}
		else if(vexRT[Btn5U]==1)	//arms up
		{
			motor[LArm] = 120;
			motor[RArm] = 100;
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

		if(SensorValue(DArmEncoders)==1)	//if jumper is in port 1
		{
			clearLCDLine(0);
  		clearLCDLine(1);
  		displayLCDPos(0,0);
  		displayNextLCDString("LArm = ");
  		displayNextLCDNumber(nMotorEncoder[LArm]);	//LArm encoder readout
  		displayLCDPos(1,0);
  		displayNextLCDString("RArm = ");
  		displayNextLCDNumber(nMotorEncoder[RArm]);	//RArm encoder readout
  	}
  	if(SensorValue(DWheelEncoders)==2)	//if jumper in port 2
		{
			clearLCDLine(0);
  		clearLCDLine(1);
  		displayLCDPos(0,0);
  		displayNextLCDString("LDrive = ");
  		displayNextLCDNumber(nMotorEncoder[LDrive]);	//LDrive encoder readout
  		displayLCDPos(1,0);
  		displayNextLCDString("RDrive = ");
  		displayNextLCDNumber(nMotorEncoder[RDrive]);	//RDrive encoder readout
 	 }
 	 if(vexRT[Btn7D] == 1)
 	 {
 	 		nMotorEncoder[LArm] = 0;
 	 		nMotorEncoder[RArm] = 0;
 	 }
	} //Infinite loop
}	//End of driver control
