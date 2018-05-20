/*
 * Motion planning problem project.
 *
 * FILE: motion_planning.cpp
 * AUTHORS:
 *   Denisov Pavel
 * LAST UPDATE: 19.05.2018
 * NOTE: motion planning class implementation file
 */

#include <glut.h>
#include "motion_planning.h"

/* Default class constructor */
MotionPlanning::MotionPlanning(void) : _rad(1.0f), _startP({-2, -2}), _finishP({-2, -2})
{
} /* End of constructor */

 /* Getting instance function */
MotionPlanning & MotionPlanning::getInstance(void)
{
  static MotionPlanning mp;
  return mp;
} /* End of 'MotionPlanning::getInstance' function */

/* Setting start point function */
void MotionPlanning::setStartPoint(const sup::Vecf &SP)
{
  _startP = SP;
  // TODO: rebuild path
} /* End of 'MotionPlanning::setStartPoint' function */

/* Setting finish point function */
void MotionPlanning::setFinishPoint(const sup::Vecf &FP)
{
  _finishP = FP;
} /* End of 'MotionPlanning::setFinishPoint' function */

/* Adding new polygon function */
void MotionPlanning::addPolygon(const Polygon &Poly)
{
  _polygons.push_back(Poly);
} /* End of 'MotionPlanning::addPolygon' function */

/* Adding vertex to last polygon function */
void MotionPlanning::addVertexToLastPolygon(const sup::Vecf &Vert, const int Index)
{
  if (_polygons.size() == 0 || _polygons.size() == Index)
    _polygons.push_back(Polygon());
  _polygons[Index].addVertex(Vert);
} /* End of 'MotionPlanning::addVertexToLastPolygon' function */

/* Drawing function */
void MotionPlanning::draw(void) const
{
  for (auto poly : _polygons)
    poly.draw();

  glPointSize(5.0f);
  glBegin(GL_POINTS);
  glColor3f(1.0f, 0.0f, 0.0f);
  glVertex2f(_startP._coords[0], _startP._coords[1]);

  glColor3f(0.0f, 0.0f, 1.0f);
  glVertex2f(_finishP._coords[0], _finishP._coords[1]);
  glEnd();
  glPointSize(1.0f);
} /* End of 'MotionPlanning::draw' function */

/* END OF 'motion_planning.cpp' FILE */
