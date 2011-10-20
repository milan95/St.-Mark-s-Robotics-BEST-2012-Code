// Game11.c
// 2011 BEST game file - includes actual game code
// Needs core functions, game year constants, and game year functions - include GameYYConstants.c, GameYYFunctions.c, and CoreTopLevel.c
// SM Robotics 2011 - Milan Savani

#include "Game11Constants.c"
#include "Game11Functions.c"
#include "CoreTopLevel.c"

task game11 ()
{
  StartTask(gameDriveControl);
  StartTask(gameArmAndServoControl);
}
