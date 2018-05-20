/*
* Motion planning problem project.
*
* FILE: vertex.h
* AUTHORS:
*   Tunikov Dmitrii
* LAST UPDATE: 19.05.2018
* NOTE: vectex class declaration file
*/
#pragma once
#include "support\support.h"
#include <vector>
#include "motion_planning\math_types\vertex.h"
#include "graph\graph.h"

class Dijkstra
{
public:
  static std::vector<Vertex> &GetGoalWay(const Vertex& start, const Vertex& goal, const std::vector<Vertex> &came_from);
  static std::vector<Vertex> &GetAllWays(const Vertex& start, const Graph<Vertex>& graph, float r);
};