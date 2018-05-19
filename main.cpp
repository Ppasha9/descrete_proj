/*
 * Motion planning problem project.
 *
 * FILE: main.cpp
 * AUTHORS:
 *   Denisov Pavel,
 *   Tunikov Dmitrii,
 *   Federov Dmitrii
 * LAST UPDATE: 04.05.2018
 * NOTE: main project file
 */

#include "anim\anim.h"

int main(int argc, char **argv)
{
  anim::Anim &anim = anim::Anim::getInstance();
  anim.init(argc, argv, 600, 600);
  anim.run();
  return 0;
} /* End of 'main' function */

/* END OF 'main.cpp' FILE */
