#pragma config(Motor,  port2,           rightDriveMotor, tmotorNormal, openLoop)
#pragma config(Motor,  port5,           servo1,        tmotorServoStandard, openLoop)
#pragma config(Motor,  port6,           servo2,        tmotorServoStandard, openLoop)
#pragma config(Motor,  port3,           leftDriveMotor, tmotorNormal, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

// Do the ROBOTC motor configurations here.
//+++++++++++++++++++++++++++++++++++++++++ | MOTOR CONFIGURATIONS | ++++++++++++++++++++++++++++++++++++++++++++++++++++++

// Main.c
// Main game file - runs everything, is called by the CORTEX first
// Needs game file - include GameYY.c
// SM Robotics 2011 - Milan Savani

#include "Game11.c"

task main ()
{

  /*
  Main is called when the Cortex starts up. It runs all of the other tasks and functions.
  In this case, it runs the "Game" function called game11.
  */

  StartTask(game11);

  while(true)
  {

  }
  StopAllTasks();

}
