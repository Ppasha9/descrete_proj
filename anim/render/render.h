/*
 * Motion planning problem project.
 *
 * FILE: render.h
 * AUTHORS:
 *   Denisov Pavel
 * LAST UPDATE: 19.05.2018
 * NOTE: render class declaration file
 */

#pragma once
#include <glut.h>
#include "../../support/support.h"

/* Animation namespace */
namespace anim
{
  /* Render class */
  class Render
  {
  public:
    /* Getting instance function */
    static Render & getInstance(void);

    /* Init function */
    void init(int Argc, char **Argv, const int W, const int H);

    /* Getting screen width function */
    int getWidth(void) const;

    /* Getting screen height function */
    int getHeight(void) const;

    /*
     * Drawing functions
     */

    /* Drawing line segment function */
    void drawSegment(const sup::Vecf &Begin, const sup::Vecf &End) const;

  private:
    /* Class default constructor */
    Render(void) : _w(0), _h(0)
    {
    }; /* End of constructor */

    /* Window size */
    int _w, _h;
  }; /* End of 'Render' class */
} /* end of 'anim' namespace */

/* END OF 'render.h' FILE */
