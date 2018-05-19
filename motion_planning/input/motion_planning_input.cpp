/*
 * Motion planning problem project.
 *
 * FILE: motion_planning_input.cpp
 * AUTHORS:
 *   Denisov Pavel
 * LAST UPDATE: 19.05.2018
 * NOTE: input motion planning implementation file
 */

#include <process.h>
#include <glut.h>
#include "motion_planning_input.h"
#include "../../anim/render/render.h"

/* Static OnKeyboard function */
void MotionPlanningInput::onKeyboard(const unsigned char Key, const int X, const int Y)
{
  if (Key == (unsigned char)HOT_KEYS::ESC)
    exit(0);

  switch (_type)
  {
  case MODE_TYPE::OBSTACLE_INPUT:
    if (Key == (unsigned char)HOT_KEYS::START_POINT_INPUT)
      _type = MODE_TYPE::START_POINT_INPUT;
    else if (Key == (unsigned char)HOT_KEYS::OBSTACLE_INPUT)
      _curPoly++;
    break;

  case MODE_TYPE::START_POINT_INPUT:
    if (Key == (unsigned char)HOT_KEYS::FINISH_POINT_INPUT)
      _type = MODE_TYPE::FINISH_POINT_INPUT;
    break;

  case MODE_TYPE::FINISH_POINT_INPUT:
    if (Key == (unsigned char)HOT_KEYS::BUILD)
      _type = MODE_TYPE::BUILDING;
    break;

  default:
    break;
  }
} /* End of 'MotionPlanningInput::onKeyboard' function */

/* OnMouse function */
void MotionPlanningInput::onMouse(const int Button, const int State, const int X, const int Y)
{
  MotionPlanning &plan = MotionPlanning::getInstance();
  anim::Render &rnd = anim::Render::getInstance();

  if (_type != MODE_TYPE::BUILDING && Button == GLUT_LEFT_BUTTON && State == GLUT_DOWN)
  {
    if (_type == MODE_TYPE::OBSTACLE_INPUT)
      plan.addVertexToLastPolygon({ X, rnd.getHeight() - Y }, _curPoly);
    else if (_type == MODE_TYPE::START_POINT_INPUT)
      plan.setStartPoint({ X, rnd.getHeight() - Y });
    else if (_type == MODE_TYPE::FINISH_POINT_INPUT)
      plan.setFinishPoint({ X, rnd.getHeight() - Y });
  }
} /* End of 'MotionPlanningInput::onMouse' function */

/* END OF 'motion_planning_input.cpp' FILE */
