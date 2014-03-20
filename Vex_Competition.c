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
  bStopTasksBetweenModes = true;

	// For all activities that occur before the competition starts
	// Example: clearing encoders, setting servo positions, ...
}

//************************ Autonomous ************************

task autonomous()
{
  // Use eqaution to simulate vex course

	AutonomousCodePlaceholderForTesting();  // Remove this function call once you have "real" code.
}



//************************ Driver Control ************************

task usercontrol() //Do This FIRST
{

	while (true)
	{
	  // Insert code here

	  UserControlCodePlaceholderForTesting(); // Remove this function call once you have "real" code.
	}
}
