/*
 * Motion planning problem project.
 *
 * FILE: vec2d.h
 * AUTHORS:
 *   Denisov Pavel
 * LAST UPDATE: 19.05.2018
 * NOTE: two-dimenshional vector class declaration file
 */
#pragma once
/* Support namespace */
namespace sup
{
  /* Two-dimenshional class */
  template<typename Type>
  class Vec2D
  {
  private:
    /* Vector components */
    Type _x, _y;

  public:
    Vec2D(Type x, Type y) : _x(x), _y(y) {}
    bool operator== (Vec2D p) const
    {
      if (_x != p._x || _y != p._y)
        return false;
      return true;
    }
    float length(Vec2D p) const
    {
      return sqrt((_x - p._x) * (_x - p._x) + (_y * p._y) * (_y * p._y));
    }
    // TODO: all mafacka
  }; /* End of 'Vec2D' class */
} /* end of 'sup' namespace */

/* END OF 'vec2d.h' FILE */
