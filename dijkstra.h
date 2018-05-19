#pragma once
#include "support\support.h"
#include <vector>
#include "motion_planning\math_types\vertex.h"
#include "graph\graph.h"

static std::vector<Vertex> &GetGoalWay(const Vertex& start, const Vertex& goal, const std::vector<Vertex> &came_from);
static std::vector<Vertex> &GetAllWays(const Vertex& start, const Graph<Vertex>& graph, float r);