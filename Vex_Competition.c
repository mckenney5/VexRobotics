#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(20)
#pragma userControlDuration(120)
#include "Vex_Competition_Includes.c"   //Main competition background code

//************************ Pre-Autonomous Functions ************************

void pre_auton()
{
  // Set bStopTasksBetweenModes to false if you want to keep user created tasks running between
  // Autonomous and Tele-Op modes. You will need to manage all user created tasks if set to false.
  bStopTasksBetweenModes = true;

	// All activities that occur before the competition starts
	// Example: clearing encoders, setting servo positions, ...
}

//************************ Autonomous ************************

task autonomous()
{
  // Use eqaution to simulate vex course

	AutonomousCodePlaceholderForTesting();  // Remove this function call once you have "real" code.
}



//************************ Driver Control ************************

task usercontrol()
{

	while (true)
	{
	  // Insert code here

	  UserControlCodePlaceholderForTesting(); // Remove this function call once you have "real" code.
	}
}
