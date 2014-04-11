int autonProgramSelect = 0; //Autonomous Switch Variable
const int noButton = 0, leftButton = 1, centerButton = 2, rightButton = 4;	//lcd button variables
string mainBattery, backupBattery;	//battery display strings
string program0 = "Program";
string program1 = "Program";
string program2 = "Program";
string program3 = "Program";
string program4 = "Program";	//program names
string program5 = "Program";
string program6 = "Program";
string program7 = "Program";
string program8 = "Program";
string program9 = "Program";
task lcdScreen();
{
	while(true)
	{
		while(bIfiRobotDisabled)	//while robot is disabled
		{
			bLCDBacklight = true;
			clearLCDLine(0);
  		clearLCDLine(1);
			displayLCDPos(0,0);
			if(autonProgramSelect==0) displayNextLCDString(program0);
			else if(autonProgramSelect==1) displayNextLCDString(program1);
			else if(autonProgramSelect==2) displayNextLCDString(program2);
			else if(autonProgramSelect==3) displayNextLCDString(program3);
			else if(autonProgramSelect==4) displayNextLCDString(program4);	//display custom program names
			else if(autonProgramSelect==5) displayNextLCDString(program5);
			else if(autonProgramSelect==6) displayNextLCDString(program6);
			else if(autonProgramSelect==7) displayNextLCDString(program7);
			else if(autonProgramSelect==8) displayNextLCDString(program8);
			else if(autonProgramSelect==9) displayNextLCDString(program9);
			else displayNextLCDString("Program");	//display "Program" if autonProgramSelect is out of range
			displayNextLCDString(" ");
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
					else if(autonProgramSelect==4) displayNextLCDString(program4);	//display custom program names
					else if(autonProgramSelect==5) displayNextLCDString(program5);
					else if(autonProgramSelect==6) displayNextLCDString(program6);
					else if(autonProgramSelect==7) displayNextLCDString(program7);
					else if(autonProgramSelect==8) displayNextLCDString(program8);
					else if(autonProgramSelect==9) displayNextLCDString(program9);
					else displayNextLCDString("Program");	//display "Program" if autonProgramSelect is out of range
					displayNextLCDString(" ");
					displayNextLCDNumber(autonProgramSelect);	//display program number
					while(nLCDButtons==rightButton){}	//wait for release
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
					else if(autonProgramSelect==4) displayNextLCDString(program4);	//display custom program names
					else if(autonProgramSelect==5) displayNextLCDString(program5);
					else if(autonProgramSelect==6) displayNextLCDString(program6);
					else if(autonProgramSelect==7) displayNextLCDString(program7);
					else if(autonProgramSelect==8) displayNextLCDString(program8);
					else if(autonProgramSelect==9) displayNextLCDString(program9);
					else displayNextLCDString("Program");	//display "Program" if autonProgramSelect is out of range
					displayNextLCDString(" ");
					displayNextLCDNumber(autonProgramSelect);	//display program number
					while(nLCDButtons==leftButton){}	//wait for release
				}
				while(nLCDButtons==centerButton)	//while center button is held down
				{
					clearLCDLine(0);
  				clearLCDLine(1);
				  displayLCDString(0, 0, "Primary: ");
					sprintf(mainBattery, "%1.2f%c", nImmediateBatteryLevel/1000.0,'V');
					displayNextLCDString(mainBattery);
					displayLCDString(1, 0, "Backup: ");
					sprintf(backupBattery, "%1.2f%c", BackupBatteryLevel/1000.0, 'V');
					displayNextLCDString(backupBattery);
				}
			}	//end program selection
			bLCDBacklight = false;
		}	//end robot disabled
		sleep(25);
	}
}
