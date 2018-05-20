/*
 * Motion planning problem project.
 *
 * FILE: graph.h
 * AUTHORS:
 *   Denisov Pavel
 *   Tunikov Dmitrii
 * LAST UPDATE: 19.05.2018
 * NOTE: graph class declaration file
 */
#pragma once
#include <vector>

/* Graph class */
template<class GraphElem, typename WeightT = float>
class Graph
{
public:
  /* Add new elem function */
  void addElem(GraphElem &NewElem)
  {
    NewElem.setId(_elements.size());
    _elements.push_back(NewElem);
  } /* End of 'addElem' function */

  /* Add new link function */
  void addLink(const int Id1, const int Id2)
  {
    _elements[Id1].addNeighbor(Id2);
    _elements[Id2].addNeighbor(Id1);
  } /* End of 'addLink' function */
  WeightT getWeight(int start, int end) const 
  {
    return _elements[start].getWeight(_elements[end]);
  }
  std::vector<GraphElem> getElements() const 
  {
    return _elements;
  }
private:
  /* Array of elements */
  std::vector<GraphElem> _elements;
}; /* End of 'Graph' class */

/* END OF 'graph.h' FILE */
