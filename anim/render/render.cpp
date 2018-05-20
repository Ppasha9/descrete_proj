/*
 * Motion planning problem project.
 *
 * FILE: render.cpp
 * AUTHORS:
 *   Denisov Pavel
 * LAST UPDATE: 19.05.2018
 * NOTE: render class implementation file
 */

#include "render.h"

using namespace anim;

/* Getting instance function */
Render & Render::getInstance(void)
{
  static Render rnd;
  return rnd;
} /* End of 'Render::getInstance' function */

/* Init function */
void Render::init(int Argc, char **Argv, const int W, const int H)
{
  _w = W;
  _h = H;

  glutInit(&Argc, Argv);
  glutInitWindowPosition(50, 50);
  glutInitWindowSize(W, H);
  glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
  glutCreateWindow("Motion Planning");

  glOrtho(0, _w, 0, _h, -5.0f, 5.0f);
} /* End of 'Render::init' function */

/* Getting screen width function */
int Render::getWidth(void) const
{
  return _w;
} /* End of 'Render::getWidth' function */

/* Getting screen height function */
int Render::getHeight(void) const
{
  return _h;
} /* End of 'Render::getHeight' function */

/* Drawing line segment function */
void Render::drawSegment(const sup::Vecf &Begin, const sup::Vecf &End) const
{
  glLineWidth(5.0f);
  glBegin(GL_LINES);
  glVertex2f(Begin._coords[0], Begin._coords[1]);
  glVertex2f(End._coords[0], End._coords[1]);
  glEnd();
} /* End of 'Render::drawSegment' function */

/* END OF 'render.cpp' FILE */
