// CoreTopLevel.c
// Top level file for the cores
// Needs control functions - include ControlCore.c
// SM Robotics 2011 - Milan Savani

#include "ControlCore.c"

//+++++++++++++++++++++++++++++++++++ | VARIABLE DECLARATIONS | ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++ | VARIABLE DECLARATIONS | ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//+++++++++++++++++++++++++++++++++++ | FUNCTION DECLARATIONS | ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
task gameDriveControl();
task gameArmAndServoControl();
//+++++++++++++++++++++++++++++++++++ | FUNCTION DECLARATIONS | ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

task gameDriveControl()
{

  int controlMode = 0;

  while(true)
  {
	    driveControlJoystickTraditional(MOTORDIVIDESLOWSPEED); // Two-joystick independent motors drive control mode - full speed
  }

}

task gameArmAndServoControl()
{
  while(true)
  {
    armControlOneJoystick();
    servoControlButton();
  }
}