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
#include <initializer_list>

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

  public:
    /* Constructor with all set params */
    template <typename DType>
    Vec2D(const std::initializer_list<DType> &Init)
    {
      size_t i = 0;
      for (auto it = Init.begin(); it != Init.end(); it++, i++)
        _coords[i] = (Type)*it;
    } /* End of 'Vector' function */

    // TODO: all mafacka
  }; /* End of 'Vec2D' class */
} /* end of 'sup' namespace */

/* END OF 'vec2d.h' FILE */
