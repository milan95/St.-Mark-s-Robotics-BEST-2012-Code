// ControlCore.c
// Core Control file - has drive, button, and other functions.
// Needs math functions - include MathCore.c
// SM Robotics 2011 - Milan Savani

#include "MathCore.c"

//+++++++++++++++++++++++++++++++++++ | VARIABLE DECLARATIONS | ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// int powerAccelValue = 0; // For driveControlAccelerometerFast and driveControlAccelerometerSlow
// int lookAccelValue = 0; // For driveControlAccelerometer and driveControlAccelerometerSlow
//+++++++++++++++++++++++++++++++++++ | VARIABLE DECLARATIONS | ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//+++++++++++++++++++++++++++++++++++ | FUNCTION DECLARATIONS | ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void servoControlButton();
void driveControlJoystickTraditional(float motorDivide); // Fast traditional drive control method that uses 2 joysticks, each responsible for its own motor
// void driveControlAccelerometer(int accelerometerThreshold, float motorDivide); // Drive control method using the accelerometer
//+++++++++++++++++++++++++++++++++++ | FUNCTION DECLARATIONS | ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void servoControlButton()
{

  if(vexRT[Btn5U] == 1 || vexRT[Btn5D] == 1)
  {
    if(vexRT[Btn5U] == 1)
    {
      motor[servo1] = 90;
    }
    else if(vexRT[Btn5D] == 1)
    {
      motor[servo1] = -90;
    }
    /*
    Put this in for return to origin
    else
    {
    motor[clawServo] = 0;
    }
    */
  }
  if(vexRT[Btn7U] == 1 || vexRT[Btn7D] == 1)
  {
    if(vexRT[Btn7U] == 1)
    {
      motor[servo2] = 60;
    }
    else if(vexRT[Btn7D] == 1)
    {
      motor[servo2] = -60;
    }
    /*
    Put this in for return to origin
    else
    {
    motor[clawServo] = 0;
    }
    */
  }

}

/*
driveControlJoystickTraditional is a method of motion using two joysticks, each responsible for a different motor. The
left joystick Y-axis is responsible for the left motor, the right joystick Y-axis is responsible for the right motor.
*/
void driveControlJoystickTraditional(float motorDivide)
{

	int rightValue = joystickNoiseFilter(vexRT[Ch2], JOYSTICKNOISETHRESHOLD); // Filters out noise from right joystick values getting slightly "stuck" near zero-values
	int leftValue = joystickNoiseFilter(vexRT[Ch3], JOYSTICKNOISETHRESHOLD); // Filters out noise from left joystick values getting slightly "stuck" near zero-values

	motor[leftDriveMotor] = leftValue / motorDivide; // Set left motor to defined value
	motor[rightDriveMotor] = rightValue / motorDivide; // Set right motor to defined value

}

/*
driveControlAccelerometer is a method of motion that uses the acceletomer, assigning a "look" value to the X-axis tilt
and a "power" value to the Y-axis tilt. The values are converted to percentages, then multiplied together. The power for
each motor is initially set to the "power" value alone, but then is added to/subtracted from, based on the "look" value.
void driveControlAccelerometer(int accelerometerThreshold, float motorDivide)
{

int accelPreviousXValue = powerAccelValue; // Set the previous X value variable to the last known X value
int accelPreviousYValue = lookAccelValue; // Set the previous Y value variable to the last known Y value

powerAccelValue = vexRT[AccelY]; // Update the Y value
lookAccelValue = vexRT[AccelX]; // Update the X value

// Check if the change in X/Y values is significant enough to merit motion (smooths out noise)
bool isSignificant = isAccelerometerMotionSignificant(accelPreviousXValue, accelPreviousYValue, powerAccelValue, lookAccelValue, accelerometerThreshold);

if(isSignificant) // If it is significant enough, then update the motors
{
int leftMotorValue = powerAccelValue + (lookAccelValue / 2); // Set left motor variable to the power plus the change in look
int rightMotorValue = powerAccelValue - (lookAccelValue / 2); // Set right motor variable to the power plus the change in look

motor[leftDriveMotor] = leftMotorValue / motorDivide;
motor[rightDriveMotor] = rightMotorValue / motorDivide;
}

wait1Msec(20); // The accelerometer generally takes 15 ms to update, so we give it some time

}
*/