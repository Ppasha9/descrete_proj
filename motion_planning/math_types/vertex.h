/*
 * Motion planning problem project.
 *
 * FILE: vertex.h
 * AUTHORS:
 *   Denisov Pavel
 * LAST UPDATE: 19.05.2018
 * NOTE: vectex class declaration file
 */

#include "../../support/support.h"

/* Vertex class */
class Vertex
{
public:
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

private:
  sup::Vecf _pos;
  int _id;
}; /* End of 'Vertex' class */

/* END OF 'vertex.h' FILE */