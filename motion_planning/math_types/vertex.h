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
  Vertex(sup::Vecf pos) : _pos(pos), _id(0) {}
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

  const std::vector<int> &getNeighbors() const
  {
    return _neighbors;
  }

  int getWeight(const Vertex &v) const
  {
    return _pos.length(v._pos);
  }

  const sup::Vecf& getPos() const
  {
    return _pos;
  }
private:
  sup::Vecf _pos;
  std::vector<int> _neighbors;
  int _id;
}; /* End of 'Vertex' class */

/* END OF 'vertex.h' FILE */
