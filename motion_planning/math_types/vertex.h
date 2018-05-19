/*
 * Motion planning problem project.
 *
 * FILE: vertex.h
 * AUTHORS:
 *   Denisov Pavel
 * LAST UPDATE: 19.05.2018
 * NOTE: vectex class declaration file
 */

#pragma once
#include "../../support/support.h"

/* Vertex class */
class Vertex
{
public:
  /* Class consturctor */
  Vertex(const sup::Vecf &Pos) : _id(0), _pos(Pos)
  {
  } /* End of constructor */

  /* Getting id function */
  int getId(void) const
  {
    return _id;
  } /* End of 'getId' function */

  /* Setting id function */
  void setId(const int ID)
  {
    _id = ID;
  } /* End of 'setId' function */

  /* Getting position function */
  sup::Vecf getPos(void) const
  {
    return _pos;
  } /* End of 'getPos' function */

  /* Setting position function */
  void setPos(const sup::Vecf &Pos)
  {
    _pos = Pos;
  } /* End of 'setPos' function */

private:
  sup::Vecf _pos;
  int _id;
}; /* End of 'Vertex' class */

/* END OF 'vertex.h' FILE */
