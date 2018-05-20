/*
 * Motion planning problem project.
 *
 * FILE: polygon.cpp
 * AUTHORS:
 *   Denisov Pavel
 * LAST UPDATE: 19.05.2018
 * NOTE: polygon class implementation file
 */

#include "polygon.h"
#include "../../anim/render/render.h"

/* Adding new vertex function */
void Polygon::addVertex(const sup::Vecf &Vert)
{
  _vertices.push_back(Vert);
} /* End of 'Polygon::addVertex' function */

/* Adding new vertex operator */
void Polygon::operator<<(const sup::Vecf &Vert)
{
  addVertex(Vert);
} /* End of 'Polygon::operator<<' operator */

/* Virtual draw function */
void Polygon::draw(void) const
{
  glColor3f(0.0f, 0.0f, 0.0f);

  if (_vertices.size() == 1)
    glBegin(GL_POINTS);
  else if (_vertices.size() == 2)
    glBegin(GL_LINES);
  else
    glBegin(GL_POLYGON);

  for (auto vert : _vertices)
    glVertex2f(vert._coords[0], vert._coords[1]);
  glEnd();
} /* End of 'Polygon::draw' function */

/* END OF 'polygon.cpp' FILE */
