#include <queue>
#include "dijkstra.h"

static std::vector<Vertex> &GetGoalWay(const Vertex& start, const Vertex& goal, const std::vector<Vertex> &came_from)
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
}

static std::vector<Vertex> &GetAllWays(const Vertex& start, const Graph<Vertex>& graph, float r)
{
  std::queue<Vertex> frontier;

  frontier.push(start);
  std::vector<Vertex> came_from;
  std::vector<int> cost_so_far(graph.getElements().size());
  came_from[start.getId()] = Vertex(sup::Vecf(-1, -1));
  cost_so_far[start.getId()] = 0;

  while (!frontier.empty()) 
  {
    Vertex current = frontier.front();
    frontier.pop();

    std::vector<int> neighbors = current.getNeighbors();
    for (auto next : neighbors)
    {
      int new_cost = cost_so_far[current.getId()] + graph.getWeight(current.getId(), next);
      if (!cost_so_far[next] || new_cost < cost_so_far[next])
      {
        cost_so_far[next] = new_cost;
        frontier.push(graph.getElements()[next]);
        came_from[next] = current;
      }
    }
  }
  return came_from;
}
