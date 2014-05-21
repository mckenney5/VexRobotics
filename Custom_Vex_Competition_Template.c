//////////////////////////////////////////////////////////////
#pragma platform(VEX)																				//
#pragma competitionControl(Competition)											//
#pragma autonomousDuration(20)															//	<---Main Competition Code
#pragma userControlDuration(120)														//				!!DO NOT MODIFY!!
#include "Tracy_and_McKenney's_Vex_LCD_Includes.h"					//
#include "Tracy_and_McKenney's_Vex_Extra_Includes.h"				//
#include "Tracy_and_McKenney's_Vex_Competition_Includes.c"	//
//////////////////////////////////////////////////////////////

void pre_auton()
{
  bStopTasksBetweenModes = false;	//Set bStopTasksBetweenModes to true to stop all tasks, including lcdSreen,
  																//immediately before and after autonomous and user control.
  																//It is recommended to set bStopTasksBetweenModes to true before the competition.
	resetAllMotorEncoders();	//Resets all motor encoders

	threshold = 15; //threshold variable for deadzones in usercontrol

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

	startTask(lcdScreen);	//Starts lcd program selection task, do not modify or remove.
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
	while(true)
	{
		analogStick(1);	//Calls value of specified analog stick on primary controller, with deadzones applied.
		partnerAnalogStick(1);	//Calls value of specified analog stick on partner controller, with deadzones applied.
	}
}	//end of driver control
