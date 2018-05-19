/*
 * Motion planning problem project.
 *
 * FILE: motion_planning_input.h
 * AUTHORS:
 *   Denisov Pavel
 * LAST UPDATE: 19.05.2018
 * NOTE: input motion planning declaration file
 */

#pragma once
#include "../motion_planning.h"

/* Hot keys */
enum struct HOT_KEYS
{
  ESC = 27,
  OBSTACLE_INPUT = 'o',
  START_POINT_INPUT = 's',
  FINISH_POINT_INPUT = 'f',
  BUILD = 'b'
}; /* End of 'HOT_KEYS' enumeration */

/* Motion planning input class */
class MotionPlanningInput
{
public:
  /* Getting instance function */
  static MotionPlanningInput & getInstance(void)
  {
    static MotionPlanningInput mpi;
    return mpi;
  } /* End of 'getInstance' function */

  /* OnKeyboard function */
  void onKeyboard(const unsigned char Key, const int X, const int Y);

  /* OnMouse function */
  void onMouse(const int Button, const int State, const int X, const int Y);

private:
  /* Default constructor */
  MotionPlanningInput(void) : _type(MODE_TYPE::OBSTACLE_INPUT), _curPoly(0)
  {
  } /* End of constructor */

  /* Mode type */
  enum struct MODE_TYPE
  {
    OBSTACLE_INPUT,
    START_POINT_INPUT,
    FINISH_POINT_INPUT,
    BUILDING,
    READY
  }; /* End of 'MODE_TYPE' enumeration */

private:
  /* Current mode */
  MODE_TYPE _type;
  /* Current polygon index */
  int _curPoly;
}; /* End of 'MotionPlanningInput' class */

/* END OF 'motion_planning_input.h' FILE */
