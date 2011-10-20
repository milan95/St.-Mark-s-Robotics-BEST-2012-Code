// MathCore.c
// Math Core file - returns math functions for ControlCore
// No dependencies
// SM Robotics 2011 - Milan Savani

//+++++++++++++++++++++++++++++++++++ | FUNCTION DECLARATIONS | ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
int joystickNoiseFilter(int joystickValueRaw, int noiseThreshold); // Filters out joystick noise caused by sticking at near-zero values
// bool isAccelerometerMotionSignificant(int prevX, int prevY, int currentX, int currentY, int threshold); // Checks if the accelerometer motion is significant enough to merit movement
//+++++++++++++++++++++++++++++++++++ | FUNCTION DECLARATIONS | ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

int joystickNoiseFilter(int joystickValueRaw, int noiseThreshold)
{

  int returnValue = 0; // Declare the return value variable

  if( (joystickValueRaw < noiseThreshold) && (joystickValueRaw > -noiseThreshold) )
  {
    returnValue = 0; // If the raw value is within the threshold on either side of the zero, set motor power to zero
  }
  else
  {
    returnValue = joystickValueRaw; // If the raw value is not within the threshold on either side of the zero, let the motor power be
  }

  return(returnValue);

}

/*
bool isAccelerometerMotionSignificant (int prevX, int prevY, int currentX, int currentY, int threshold)
{

  bool isSignificant; // Declare the variable so we can access it within the if

  if( (abs(currentX - prevX) > threshold) || (abs(currentY - prevY) > threshold) ) // Check if the change from the previous values for X or Y are greater than the threshold
  {
    if ( (abs(currentX) > threshold) || (abs(currentY) > threshold) ) // Check if the X and Y values are within the threshold from 0
    {
      isSignificant = true; // If they're not, then set isSignificant to true
    }
  }
  else
  {
    isSignificant = false; // If they are, then set isSignificant to false
  }

  return(isSignificant); // Return isSignificant

}
*/