/*
 * Motion planning problem project.
 *
 * FILE: polygon.h
 * AUTHORS:
 *   Denisov Pavel
 * LAST UPDATE: 19.05.2018
 * NOTE: polygon class declaration file
 */

#pragma once
#include <vector>
#include "../../support/support.h"
#include "../../anim/render/drawable/drawable.h"

/* Polygon class */
class Polygon : public Drawable
{
public:
  /* Adding new vertex function */
  void addVertex(const sup::Vecf &Vert);

  /* Adding new vertex operator */
  void operator<<(const sup::Vecf &Vert);

  /* Virtual draw function */
  virtual void draw(void) const;

private:
  /* Array of vertices */
  std::vector<sup::Vecf> _vertices;
}; /* End of 'Polygon' class */

/* END OF 'polygon.h' FILE */
