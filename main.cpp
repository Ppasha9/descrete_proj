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

#include <iostream>
#include "graph\graph.h"
#include "motion_planning\math_types\vertex.h"
#include "support\support.h"
#include "support\vec2d.h"
#include "dijkstra.h"

int main(void)
{
  Graph<Vertex> gr;
  gr.addElem(Vertex(sup::Vecf(0.1, 0.1)));
  gr.addElem(Vertex(sup::Vecf(0.2, 0.3)));
  gr.addElem(Vertex(sup::Vecf(0.1, 0.7)));
  gr.addElem(Vertex(sup::Vecf(0.6, 0.8)));
  gr.addElem(Vertex(sup::Vecf(0.9, 0.2)));

  gr.addLink(0, 1);
  gr.addLink(0, 2);
  gr.addLink(0, 3);
  gr.addLink(1, 2);
  gr.addLink(3, 4);
  gr.addLink(2, 3);
  gr.addLink(1, 4);


  std::vector<Vertex> came_from = Dijkstra::GetAllWays(gr.getElements()[0], gr, 0.1);
  std::cout << "Hui!" << std::endl;
  return 0;
}

/* END OF 'main.cpp' FILE */
