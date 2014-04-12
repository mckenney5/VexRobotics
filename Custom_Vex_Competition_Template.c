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
  bStopTasksBetweenModes = false;	//Set bStopTasksBetweenModes to true to stop all tasks immediately before and after autonomous and user control.
  																//It is recommended to set bStopTasksBetweenModes to true right before the competition.
	resetAllEncoders();	//Resets all motor encoders. This will not work if you are using the standard "Vex_Competition_Includes" file.

	program0 = "Program";
	program1 = "Program";
	program2 = "Program";
	program3 = "Program";
	program4 = "Program";	//Name your autonomous programs here. The numbers here match the case numbers in autonomous.
	program5 = "Program";
	program6 = "Program";
	program7 = "Program";
	program8 = "Program";
	program9 = "Program";

	startTask(lcdScreen);	//start lcd program selection task
}
task autonomous()
{
	clearTimer(T1);	//start autonomous timer
	autonReset:
	switch(autonProgramSelect)
	{
		case 0:

		break;
		case 1:

		break;
		case 2:

		break;
		case 3:

		break;
		case 4:

		break;
		case 5:

		break;
		case 6:

		break;
		case 7:

		break;
		case 8:

		break;
		case 9:

		break;
		default:	//this will run if selected auton program does not exist
			autonProgramSelect = 0;	//prepare to run program 0
			clearLCDLine(0);
			clearLCDLine(1);
			displayLCDPos(0,0);
			displayNextLCDString(program0);	//display name of program 0
			displayNextLCDString(" ");
			displayNextLCDNumber(autonProgramSelect);	//display number of program 0
			displayLCDCenteredString(1,"Running as Default");
			goto autonReset;	//restart autonomous segment
		break;
	}
}	//end of autonomous

task usercontrol()
{
	while(true)	//infinite loop
	{
		//driver control code here
	}
}	//end of driver control
