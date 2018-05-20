/*
 * Motion planning problem project.
 *
 * FILE: support.h
 * AUTHORS:
 *   Denisov Pavel
 *   Tunikov Dmitrii
 * LAST UPDATE: 19.05.2018
 * NOTE: support class declaration file
 */
#pragma once
#include "vec2d.h"

/* Support namespace */
namespace sup
{
  /* Type definitions */
  struct Line
  {
    float _k, _b;
    Line(float k = 0, float b = 0) : _k(k), _b(b) {}
  };
  const float eps = 0.0000001;
  using Vecf = Vec2D<float>;
  using Veci = Vec2D<int>;
  using Vecd = Vec2D<double>;

  bool isIntersectionCircleLine(Line line, Vecf c, float r)
  {
    float d = (pow((2 * line._k* line._b - 2 * c._x - 2 * c._y * line._k), 2) - (4 + 4 * line._k * line._k) * 
       (line._b * line._b - r*r + c._x * c._x + c._y * c._y - 2 * c._x * line._b));
    if (d < 0)
      return false;
    return true;
  }//end of 'isIntersectionCircleLine' function

  Line getLineEq(Vecf p1, Vecf p2)
  {
    Line line;
    line._k = (p2._x - p1._x) / (p2._y - p1._y);
    line._b = p1._y - line._k * p1._x;
    return line;
  }//end of 'getLineQe' function

  float getFX(Line line, float x)
  {
    return line._k * x + line._b;
  }//end of 'getFX' function
} /* end of 'sup' namespace */

/* END OF 'support.h' FILE */
