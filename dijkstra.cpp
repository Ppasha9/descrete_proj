/*
* Motion planning problem project.
*
* FILE: vertex.h
* AUTHORS:
*   Tunikov Dmitrii
* LAST UPDATE: 19.05.2018
* NOTE: vectex class declaration file
*/
#include <queue>
#include "dijkstra.h"
#include "support\support.h"
#include "support\vec2d.h"
#include <cmath>

std::vector<Vertex>& Dijkstra::GetGoalWay(const Vertex& start, const Vertex& goal, const std::vector<Vertex> &came_from)
{
  Vertex current = goal;
  std::vector<Vertex> path;
  path.push_back(current);

  while (!(current.getPos() == start.getPos())) 
  {
    current = came_from[current.getId()];
    path.push_back(current);
  }
  path.push_back(start);
  std::reverse(path.begin(), path.end());
  return path;
}//end of 'GetGoalWay' function

bool isIntersectionBoxBox()
{

}

bool isIntersection(float r, sup::Vecf p1, sup::Vecf p2)
{
  sup::Line line = sup::getLineEq(p1, p2);
  float x = p1._x < p2._x ? p1._x : p2._x;
  float end = fabs(x - p1._x) < sup::eps ? p1._x : p2._x;
  
  for (; x <= end; x += 0.05)
    if (sup::isIntersectionCircleLine(line, sup::Vecf(x, sup::getFX(line, x)), r));
      return true;
  return false;
}

std::vector<Vertex>& Dijkstra::GetAllWays(const Vertex& start, const Graph<Vertex>& graph, float r)
{
  std::queue<Vertex> frontier;

  frontier.push(start);
  const std::vector<Vertex> graph_vert = graph.getElements();
  std::vector<Vertex> came_from(graph_vert.size());
  std::vector<float> cost_so_far(graph_vert.size());
  came_from[start.getId()] = Vertex(sup::Vecf(-1, -1));
  cost_so_far[start.getId()] = 0;

  while (!frontier.empty()) 
  {
    Vertex current = frontier.front();
    frontier.pop();

    //add neighbors to frontier 
    std::vector<int> neighbors = current.getNeighbors();
    for (auto next : neighbors)
    {
      //check Intersection circle with polygons
      if (isIntersection(r, current.getPos(), graph_vert[next].getPos()))
        continue;
      //check cost of this move
      float new_cost = cost_so_far[current.getId()] + graph.getWeight(current.getId(), next);
      if (!cost_so_far[next] || new_cost < cost_so_far[next])
      {
        cost_so_far[next] = new_cost;
        frontier.push(graph.getElements()[next]);
        came_from[next] = current;
      }
    }
  }
  return came_from;
}//end of 'GetAllWays' function
