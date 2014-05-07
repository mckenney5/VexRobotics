//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//          Christian Tracy and Adam McKenney's Custom VEX Competition Control Include File
//
//	This file provides control over a VEX Competition Match. It should be included in the user's
//	program with the following line located near the start of the user's program
//
//        #include "Tracy_and_McKenney's_Vex_Competition_Includes.c"
//
//	The above statement will cause this program to be included in the user's program. There's no
//	need to modify this program.
//
//	This file is based on the original template available by default in RobotC. It has been modified
//	from the default version in the following ways:
//		Removed all interaction with the LCD screen.
//		Altered bStopTasksBetweenModes to stop tasks every time the robot is disabled,
//			instead of only between autonomous and usercontrol.
//		Removed UserControlCodePlaceholderForTesting() and AutonomousCodePlaceholderForTesting().
//		Removed displayStatusAndTime().
//		Added resetAllEncoders() function. This resets all I2C motor encoders when called.
//////////////////////////////////////////////////////////////////////////////////////////////////////
void allMotorsOff();
void allTasksStop();
void pre_auton();
task autonomous();
task usercontrol();

void resetAllEncoders();

// int nTimeXX = 0;
bool bStopTasksBetweenModes = true;

// static void displayStatusAndTime();

task main()
{
  // Master CPU will not let competition start until powered on for at least 2-seconds
   clearLCDLine(0);
   clearLCDLine(1);
   displayLCDPos(0, 0);
   displayNextLCDString("Startup");
   wait1Msec(2000);

  pre_auton();

  wait1Msec(500);


  while (true)
  {

    // clearLCDLine(0);
    // clearLCDLine(1);
    // displayLCDPos(0, 0);

    while (bIfiRobotDisabled)
    {
    	sleep(25);
      // displayLCDPos(0, 0);
      // displayNextLCDString("Disabled");
      // nTimeXX = 0;
      //while (true)
      //{
        //displayStatusAndTime();
        //if (!bIfiRobotDisabled) break;
        //wait1Msec(25);

        // displayStatusAndTime();
        // if (!bIfiRobotDisabled)
        // break;
        // wait1Msec(25);

        // displayStatusAndTime();
        // if (!bIfiRobotDisabled)
        // break;
        // wait1Msec(25);

        // displayStatusAndTime();
        // if (!bIfiRobotDisabled)
        // break;
        // wait1Msec(25);
        // ++nTimeXX;
      //}
    }

    // nTimeXX = 0;
    // clearLCDLine(0);
    // clearLCDLine(1);
    // displayLCDPos(0, 0);
    if (bIfiAutonomousMode)
    {
    	if(bStopTasksBetweenModes) allTasksStop();	//stop all tasks before auton
      // displayNextLCDString("Autonomous");
      startTask(autonomous);

      // Waiting for autonomous phase to end
      while (bIfiAutonomousMode && !bIfiRobotDisabled)
      {
        if (!bVEXNETActive)
        {
          if (nVexRCReceiveState == vrNoXmiters) // the transmitters are powered off!!
            allMotorsOff();
        }
        wait1Msec(25);               // Waiting for autonomous phase to end
      }
      allMotorsOff();
      if(bStopTasksBetweenModes)
      {
        allTasksStop();
      }
    }

    else
    {
    	if(bStopTasksBetweenModes) allTasksStop();	//stop all tasks before user control
      // displayNextLCDString("User Control");
      startTask(usercontrol);

      // Here we repeat loop waiting for user control to end and (optionally) start
      // of a new competition run
      while (!bIfiAutonomousMode && !bIfiRobotDisabled)
      {
        if (nVexRCReceiveState == vrNoXmiters) // the transmitters are powered off!!
          allMotorsOff();
        wait1Msec(25);
      }
      allMotorsOff();
      if(bStopTasksBetweenModes)
      {
        allTasksStop();
      }
    }
  }
}


void allMotorsOff()
{
  motor[port1] = 0;
  motor[port2] = 0;
  motor[port3] = 0;
  motor[port4] = 0;
  motor[port5] = 0;
  motor[port6] = 0;
  motor[port7] = 0;
  motor[port8] = 0;
#if defined(VEX2)
  motor[port9] = 0;
  motor[port10] = 0;
#endif
}

void allTasksStop()
{
  stopTask(1);
  stopTask(2);
  stopTask(3);
  stopTask(4);
#if defined(VEX2)
  stopTask(5);
  stopTask(6);
  stopTask(7);
  stopTask(8);
  stopTask(9);
  stopTask(10);
  stopTask(11);
  stopTask(12);
  stopTask(13);
  stopTask(14);
  stopTask(15);
  stopTask(16);
  stopTask(17);
  stopTask(18);
  stopTask(19);
#endif
}

void resetAllEncoders()	//resets all motor encoders
{
	resetMotorEncoder(port1);
	resetMotorEncoder(port2);
	resetMotorEncoder(port3);
	resetMotorEncoder(port4);
	resetMotorEncoder(port5);
	resetMotorEncoder(port6);
	resetMotorEncoder(port7);
	resetMotorEncoder(port8);
	resetMotorEncoder(port9);
	resetMotorEncoder(port10);
}

/*static void displayStatusAndTime()
{
  displayLCDPos(1, 0);
	if (bIfiRobotDisabled)
	  displayNextLCDString("Disable ");
	else
	{
	  if (bIfiAutonomousMode)
	    displayNextLCDString("Auton  ");
	  else
	    displayNextLCDString("Driver ");
	}
	displayNextLCDNumber(nTimeXX / 600, 2);
	displayNextLCDChar(':');
	displayNextLCDNumber((nTimeXX / 10) % 60, -2);
	displayNextLCDChar('.');
	displayNextLCDNumber(nTimeXX % 10, 1);
}

static void UserControlCodePlaceholderForTesting()
{
  // Following code is simply for initial debuggging.
  //
  // It can be safely removed in a real program	and removing it will slightly improve the
  // real-time performance of your robot.
	//
  displayStatusAndTime();
	wait1Msec(100);
	++nTimeXX;
}

static void AutonomousCodePlaceholderForTesting()
{
	// This is where you insert your autonomous code. Because we don't have any, we'll
	// simply display a running count of the time on the VEX LCD.

	while (true)
	{
	  displayStatusAndTime();
		wait1Msec(100);
		++nTimeXX;
	}
}*/

//!!DON'T PLAY WITH THE VISE!!//
