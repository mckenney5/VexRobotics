//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//																																																					//
//	Christian Tracy and Adam McKenney's Custom VEX LCD Screen Interface and Program Selection Include File	//
//																																																					//
//	This file facilitates the use of multiple different autonomous programs, selected using the LCD screen.	//
// 	It should be included in the user's program with the following line near the start of the program.			//
//																																																					//
//        #include "Tracy_and_McKenney's_Vex_Competition_Includes.c"																				//
//																																																					//
//	The above statement will cause this program to be included in the user's program.												//
//	There is no need to modify this program.																																//
//																																																					//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

task lcdScreen();	//functions declared here, and not before task main, to allow for replacement/removal of one
void prepareToRunDefaultAutonProgram(int defaultAutonProgram);	//include file without affecting the other
int autonProgramSelect = 0; //Autonomous Switch Variables
const int noButton = 0, leftButton = 1, centerButton = 2, rightButton = 4;	//lcd button variables
string mainBattery, backupBattery;	//battery display strings
string program0 = "Program";
string program1 = "Program";
string program2 = "Program";
string program3 = "Program";
string program4 = "Program";	//program names
string program5 = "Program";	//these can be changed during pre_auton()
string program6 = "Program";
string program7 = "Program";
string program8 = "Program";
string program9 = "Program";
task lcdScreen()
{
	while(true)
	{
		while(bIfiRobotDisabled)	//while robot is disabled
		{
			bLCDBacklight = true;	//turn on backlight
			clearLCDLine(0);
			clearLCDLine(1);
			displayLCDPos(0,0);
			if(autonProgramSelect==0) displayNextLCDString(program0);
			else if(autonProgramSelect==1) displayNextLCDString(program1);
			else if(autonProgramSelect==2) displayNextLCDString(program2);
			else if(autonProgramSelect==3) displayNextLCDString(program3);
			else if(autonProgramSelect==4) displayNextLCDString(program4);	//display custom program name
			else if(autonProgramSelect==5) displayNextLCDString(program5);
			else if(autonProgramSelect==6) displayNextLCDString(program6);
			else if(autonProgramSelect==7) displayNextLCDString(program7);
			else if(autonProgramSelect==8) displayNextLCDString(program8);
			else if(autonProgramSelect==9) displayNextLCDString(program9);
			else displayNextLCDString("Program");	//display "Program" if autonProgramSelect is out of range
			displayNextLCDString(" ");	//display one space
			displayNextLCDNumber(autonProgramSelect);	//display program number
			displayLCDCenteredString(1,"<     Batt     >");	//display navigation

			while(bIfiRobotDisabled)	//while robot is disabled
			{
				if(nLCDButtons==rightButton)	//if right button pressed
				{
					autonProgramSelect++;	//next program
					clearLCDLine(0);
					displayLCDPos(0,0);
					if(autonProgramSelect==0) displayNextLCDString(program0);
					else if(autonProgramSelect==1) displayNextLCDString(program1);
					else if(autonProgramSelect==2) displayNextLCDString(program2);
					else if(autonProgramSelect==3) displayNextLCDString(program3);
					else if(autonProgramSelect==4) displayNextLCDString(program4);	//display custom program name
					else if(autonProgramSelect==5) displayNextLCDString(program5);
					else if(autonProgramSelect==6) displayNextLCDString(program6);
					else if(autonProgramSelect==7) displayNextLCDString(program7);
					else if(autonProgramSelect==8) displayNextLCDString(program8);
					else if(autonProgramSelect==9) displayNextLCDString(program9);
					else displayNextLCDString("Program");	//display "Program" if autonProgramSelect is out of range
					displayNextLCDString(" ");	//display one space
					displayNextLCDNumber(autonProgramSelect);	//display program number
					while(nLCDButtons!=noButton){}	//wait for release
				}
				else if(nLCDButtons==leftButton)	//if left button pressed
				{
					autonProgramSelect--;	//previous program
					clearLCDLine(0);
					displayLCDPos(0,0);
					if(autonProgramSelect==0) displayNextLCDString(program0);
					else if(autonProgramSelect==1) displayNextLCDString(program1);
					else if(autonProgramSelect==2) displayNextLCDString(program2);
					else if(autonProgramSelect==3) displayNextLCDString(program3);
					else if(autonProgramSelect==4) displayNextLCDString(program4);	//display custom program name
					else if(autonProgramSelect==5) displayNextLCDString(program5);
					else if(autonProgramSelect==6) displayNextLCDString(program6);
					else if(autonProgramSelect==7) displayNextLCDString(program7);
					else if(autonProgramSelect==8) displayNextLCDString(program8);
					else if(autonProgramSelect==9) displayNextLCDString(program9);
					else displayNextLCDString("Program");	//display "Program" if autonProgramSelect is out of range
					displayNextLCDString(" ");	//display one space
					displayNextLCDNumber(autonProgramSelect);	//display program number
					while(nLCDButtons!=noButton){}	//wait for release
				}
				else if(nLCDButtons==centerButton)	//if center button pressed
				{
					while(nLCDButtons==centerButton)	//while center button pressed
					{
						clearLCDLine(0);
						clearLCDLine(1);
						displayLCDString(0, 0, "Primary: ");
						sprintf(mainBattery, "%1.2f%c", nImmediateBatteryLevel/1000.0,'V');	//build value to be displayed
						displayNextLCDString(mainBattery);	//display main battery level
						displayLCDString(1, 0, "Backup: ");
						sprintf(backupBattery, "%1.2f%c", BackupBatteryLevel/1000.0, 'V');	//build value to be displayed
						displayNextLCDString(backupBattery);	//display backup battery level
						sleep(25);	//wait 25ms
					}	//end while
					clearLCDLine(0);
					clearLCDLine(1);
					displayLCDPos(0,0);
					if(autonProgramSelect==0) displayNextLCDString(program0);
					else if(autonProgramSelect==1) displayNextLCDString(program1);
					else if(autonProgramSelect==2) displayNextLCDString(program2);
					else if(autonProgramSelect==3) displayNextLCDString(program3);
					else if(autonProgramSelect==4) displayNextLCDString(program4);	//display custom program name
					else if(autonProgramSelect==5) displayNextLCDString(program5);
					else if(autonProgramSelect==6) displayNextLCDString(program6);
					else if(autonProgramSelect==7) displayNextLCDString(program7);
					else if(autonProgramSelect==8) displayNextLCDString(program8);
					else if(autonProgramSelect==9) displayNextLCDString(program9);
					else displayNextLCDString("Program");	//display "Program" if autonProgramSelect is out of range
					displayNextLCDString(" ");	//display one space
					displayNextLCDNumber(autonProgramSelect);	//display program number
					displayLCDCenteredString(1,"<     Batt     >");	//display navigation
				}	//end battery display
			}	//end program selection
			bLCDBacklight = false;	//turn off backlight
		}	//end robot disabled
		abortTimeslice();	//allow other tasks to run
	}	//end infinite loop
}	//end task lcdscreen
void prepareToRunDefaultAutonProgram(int defaultAutonProgram)
{
	bLCDBacklight = true; //turn on backlight
	autonProgramSelect = defaultAutonProgram;	//prepare to run selected default auton program
	clearLCDLine(0);
	clearLCDLine(1);
	displayLCDPos(0,0);
	if(autonProgramSelect==0) displayNextLCDString(program0);
	else if(autonProgramSelect==1) displayNextLCDString(program1);
	else if(autonProgramSelect==2) displayNextLCDString(program2);
	else if(autonProgramSelect==3) displayNextLCDString(program3);
	else if(autonProgramSelect==4) displayNextLCDString(program4);	//display custom program name
	else if(autonProgramSelect==5) displayNextLCDString(program5);
	else if(autonProgramSelect==6) displayNextLCDString(program6);
	else if(autonProgramSelect==7) displayNextLCDString(program7);
	else if(autonProgramSelect==8) displayNextLCDString(program8);
	else if(autonProgramSelect==9) displayNextLCDString(program9);
	else displayNextLCDString("Program");	//display "Program" if autonProgramSelect is out of range
	displayNextLCDString(" ");	//display one space
	displayNextLCDNumber(autonProgramSelect);	//display number of default program
	displayLCDCenteredString(1,"Running as Default");
}
