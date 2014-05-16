//////////////////////////////////////////////////////////////
#pragma platform(VEX)																				//
#pragma competitionControl(Competition)											//
#pragma autonomousDuration(20)															//	<---Main Competition Code
#pragma userControlDuration(120)														//				!!DO NOT MODIFY!!
#include "Tracy_and_McKenney's_Vex_Competition_Includes.c"	//
#include "Tracy_and_McKenney's_Vex_LCD_Includes.h"					//
//////////////////////////////////////////////////////////////

void pre_auton()
{
  bStopTasksBetweenModes = false;	//Set bStopTasksBetweenModes to true to stop all tasks, including lcdSreen,
  																//immediately before and after autonomous and user control.
  																//It is recommended to set bStopTasksBetweenModes to true before the competition.
	resetAllEncoders();	//Resets all motor encoders. This won't work if using the standard "Vex_Competition_Includes"

	program0 = "Program";
	program1 = "Program";
	program2 = "Program";
	program3 = "Program";
	program4 = "Program";	//Name your autonomous programs here. Numbers here match the case numbers in autonomous.
	program5 = "Program";
	program6 = "Program";
	program7 = "Program";
	program8 = "Program";
	program9 = "Program";

	startTask(lcdScreen);	//starts lcd program selection task, do not modify or remove.
}

task autonomous()
{
	autonReset:	//autonomous segment restart point
	switch(autonProgramSelect)
	{
		case 0:
			//program0 code here
			break;
		case 1:
			//program1 code here
			break;
		case 2:
			//program2 code here
			break;
		case 3:
			//program3 code here
			break;
		case 4:
			//program4 code here
			break;
		case 5:
			//program5 code here
			break;
		case 6:
			//program6 code here
			break;
		case 7:
			//program7 code here
			break;
		case 8:
			//program8 code here
			break;
		case 9:
			//program9 code here
			break;
		default:	//this will run if selected case does not exist
			prepareToRunDefaultAutonProgram(0);	//prepare to run the case that matches the number here
			goto autonReset;	//restart autonomous segment
			break;
	}
}	//end of autonomous

task usercontrol()
{
	int c1=0,c2=0,c3=0,c4=0;	//deadzone variables, use these to call analog sticks
	while(true)	//infinite loop
	{
																										//$Calculate Deadzones$
		if(abs(vexRT[Ch1]) > 15) //1 Axis
			c1 = vexRT[Ch1];
		else
			c1 = 0;
		if(abs(vexRT[Ch2]) > 15) //2 Axis
			c2 = vexRT[Ch2];
		else
			c2 = 0;
		if(abs(vexRT[Ch3]) > 15) //3 Axis
			c3 = vexRT[Ch3];
		else
			c3 = 0;
		if(abs(vexRT[Ch4]) > 15) //4 Axis
			c4 = vexRT[Ch4];
		else
			c4 = 0;
																										//$$End Deadzones$$
		//driver control code here
	}
}	//end of driver control
