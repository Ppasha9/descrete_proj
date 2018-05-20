/*
 * Motion planning problem project.
 *
 * FILE: vec2d.h
 * AUTHORS:
 *   Denisov Pavel
 *   Tunikov Dmitrii
 * LAST UPDATE: 19.05.2018
 * NOTE: two-dimenshional vector class declaration file
 */

#pragma once
#include <initializer_list>

#pragma once
/* Support namespace */
namespace sup
{
  /* Two-dimenshional class */
  template<typename Type>
  class Vec2D
  {
  public:
    /* Vector components */
    Type _coords[2];

    Vec2D() {}
  public:
    /* Constructor with all set params */
    template <typename DType>
    Vec2D(const std::initializer_list<DType> &Init)
    {
      size_t i = 0;
      for (auto it = Init.begin(); it != Init.end(); it++, i++)
        _coords[i] = (Type)*it;
    } /* End of 'Vector' function */

    Vec2D(Type x, Type y) : _coords[0](x), _coords[1](y) {}
    bool operator== (Vec2D p) const
    {
      if (fabs(_coords[0] - p._coords[0]) > eps || fabs(_coords[1] - p._coords[1]) > eps)
        return false;
      return true;
    }
    float length(Vec2D p) const
    {
      return sqrt((_coords[0] - p._coords[0]) * (_coords[0] - p._coords[0]) + (_coords[1] - p._coords[1]) * (_coords[1] - p._coords[1]));
    }
    // TODO: all mafacka
  }; /* End of 'Vec2D' class */
} /* end of 'sup' namespace */

/* END OF 'vec2d.h' FILE */
