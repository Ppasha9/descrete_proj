/*
 * Motion planning problem project.
 *
 * FILE: motion_planning.h
 * AUTHORS:
 *   Denisov Pavel
 * LAST UPDATE: 19.05.2018
 * NOTE: motion planning class declaration file
 */

#pragma once
#include "../graph/graph.h"
#include "math_types\vertex.h"
#include "math_types\polygon.h"

/* Motion planning algorithm class */
class MotionPlanning
{
public:
  /* Getting instance function */
  static MotionPlanning & getInstance(void);

  /* Setting start point function */
  void setStartPoint(const sup::Vecf &SP);

  /* Setting finish point function */
  void setFinishPoint(const sup::Vecf &FP);

  /* Adding new polygon function */
  void addPolygon(const Polygon &Poly);

  /* Adding vertex to last polygon function */
  void addVertexToLastPolygon(const sup::Vecf &Vert, const int Index);

  /* Drawing function */
  void draw(void) const;

private:
  /* Default class constructor */
  MotionPlanning(void);

  /* Visibility graph */
  Graph<Vertex> _visGraph;
  /* Came_from vector of vertices for path */
  std::vector<Vertex> _cameFrom;
  /* Current radius of the "agent" */
  float _rad;

  /* Polygon array */
  std::vector<Polygon> _polygons;
  /* Start and finish points */
  sup::Vecf _startP, _finishP;
}; /* End of 'MotionPlanning' class */

/* END OF 'motion_planning.h' FILE */
