#pragma config(Sensor, S2,     IROne,          sensorI2CCustom)
#pragma config(Sensor, S3,     IRTwo,          sensorI2CCustom)
#pragma config(Sensor, S1, , sensorI2CCustom)

/*
#pragma config(Motor,  mtr_S1_C1_1,     motorD,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     motorE,        tmotorTetrix, openLoop, reversed)
#pragma config(Servo,  srvo_S1_C2_1,    servo1,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_2,    servo2,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_6,    servo6,               tServoNone)
*/
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//


#include "JoystickDriver.c"
#include "../Libraries/Motors.h"
#include "Isaac's Code/Full Program.c"

// example.c

/*

	(C) Copyright 2014 Matthew Kelsey, Duncan McKee, Jesse Walling and Duncan Clark
	This file is part of the FTC team 6157 application code.

	FTC team 6157 application code is free software: you c	an
	redistribute it and/or modify it under the terms of the GNU
	General Public License as published by the Free Software
	Foundation, either version 2 of the License, or (at your
	option) any later version.

	FTC team 6157 application code is distributed in the hope that
	it will be useful, but WITHOUT ANY WARRANTY; without even the
	implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
	PURPOSE.  See the GNU General Public License for more details.

	You should have received a copy of the GNU General Public
	License along with FTC team 6157 application code. If not, see
	<http://www.gnu.org/licenses/>.

*/


float multiplier = 2.0; //This variable can account for different gear ratios between robots.
//17 for 1.0 forward on test bot

/*			FORWARD			*/

void forward(float rotations)
{
	int StartPosition1 = Motors_GetPosition(S1, 1, 1);
	int StartPosition2 = Motors_GetPosition(S1, 1, 2);

	while(Motors_GetPosition(S1, 1, 1) < StartPosition1 + rotations * 1440 * multiplier && Motors_GetPosition(S1, 1, 2) < StartPosition2 + rotations * 1440 * multiplier)
	{
		Motors_SetSpeed(S1, 1, 1, 100);
		Motors_SetSpeed(S1, 1, 2, -100);
	}

		Motors_SetSpeed(S1, 1, 1, 0);
		Motors_SetSpeed(S1, 1, 2, 0);
}

/*			RIGHT			*/

void turnR(float time)
{
	Motors_SetSpeed(S1, 1, 1, 100);
	Motors_SetSpeed(S1, 1, 2, 100);
	Sleep(time*1000);
	Motors_SetSpeed(S1, 1, 1, 0);
	Motors_SetSpeed(S1, 1, 2, 0);

}

/*			LEFT			*/

void turnL(float time)
{
	Motors_SetSpeed(S1, 1, 1, -100);
	Motors_SetSpeed(S1, 1, 2, -100);
	Sleep(time*1000);
	Motors_SetSpeed(S1, 1, 1, 0);
	Motors_SetSpeed(S1, 1, 2, 0);

}
/*			BACKWARD			*/

void backward(float rotations)
{
	int StartPosition1 = Motors_GetPosition(S1, 1, 1);
	int StartPosition2 = Motors_GetPosition(S1, 1, 2);

	while(Motors_GetPosition(S1, 1, 1) > StartPosition1 - rotations * 1440 * multiplier && Motors_GetPosition(S1, 1, 2) > StartPosition2 - rotations * 1440 * multiplier)
	{
		Motors_SetSpeed(S1, 1, 1, -100);
		Motors_SetSpeed(S1, 1, 2, 100);
	}

		Motors_SetSpeed(S1, 1, 1, 0);
		Motors_SetSpeed(S1, 1, 2, 0);
}

task main()
{


	int Configuration = 1;//CheckPosition();

	if(Configuration == 1)
	{
		//CONFIGURATION 1
		turnL(1);
		forward(0.6);
	}
	else if(Configuration == 3)
	{

		//CONFIGURATION 3
		//turnR(0.7);
		//forward(2.5);
		//turnL(1.4);
		//int Configuration = CheckPosition();
		//if(Configuration == 1)
		//{
		//	turnR(1.5);
		//	forward(0.9);
		//	turnL(1.5);
		//	forward(2.3);
		//	turnL(1.4);
		//	forward(1.0);
		//}else{
		//	forward(2.0);
		//	turnR(0.7);
		//	forward(2.0);
		//}
	turnR(1.5);
	forward(0.9);
	turnL(1.5);
	forward(4.0);

	}
	else
	{
		//CONFIGURATION 2
		turnL(0.3);
		forward(1.5);
		turnR(1.0);
		forward(2.0);
	}

}
