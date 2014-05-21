int threshold = 15;	//Threshold value for deadzones. Not a constant to allow for editing in main file by end user.
void resetAllMotorEncoders();
int analogStick(int calledAnalogStick);
int partnerAnalogStick(int partnerCalledAnalogStick);
void resetAllMotorEncoders()	//resets all motor encoders
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
int analogStick(int calledAnalogStick)
{	//Calls value of specified analog stick on primary controller, with deadzones applied.
	switch(calledAnalogStick)
	{
		case 1: //Axis 1
			if(abs(vexRT[Ch1]) > threshold)
				return vexRT[Ch1];
			else
				return 0;
			break;
		case 2:	//Axis 2
			if(abs(vexRT[Ch2]) > threshold)
				return vexRT[Ch2];
			else
				return 0;
			break;
		case 3:	//Axis 3
			if(abs(vexRT[Ch3]) > threshold)
				return vexRT[Ch3];
			else
				return 0;
			break;
		case 4:	//Axis 4
			if(abs(vexRT[Ch4]) > threshold)
				return vexRT[Ch4];
			else
				return 0;
			break;
		default:	//if calledAnalogstick out of range
			return 0;
	}
}
int partnerAnalogStick(int partnerCalledAnalogStick)
{	//Calls value of specified analog stick on partner controller, with deadzones applied.
	switch(partnerCalledAnalogStick)
	{
		case 1: //Partner Axis 1
			if(abs(vexRT[Ch1Xmtr2]) > threshold)
				return vexRT[Ch1Xmtr2];
			else
				return 0;
			break;
		case 2:	//Partner Axis 2
			if(abs(vexRT[Ch2Xmtr2]) > threshold)
				return vexRT[Ch2Xmtr2];
			else
				return 0;
			break;
		case 3:	//Partner Axis 3
			if(abs(vexRT[Ch3Xmtr2]) > threshold)
				return vexRT[Ch3Xmtr2];
			else
				return 0;
			break;
		case 4:	//Partner Axis 4
			if(abs(vexRT[Ch4Xmtr2]) > threshold)
				return vexRT[Ch4Xmtr2];
			else
				return 0;
			break;
		default:	//if partnerCalledAnalogStick out of range
			return 0;
	}
}
