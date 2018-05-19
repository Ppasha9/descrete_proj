/*
 * Motion planning problem project.
 *
 * FILE: graph.h
 * AUTHORS:
 *   Denisov Pavel
 * LAST UPDATE: 19.05.2018
 * NOTE: graph class declaration file
 */

#pragma once
#include <vector>

/* Graph class */
template<class GraphElem>
template<class GraphElem, typename WeightT = float>
class Graph
{
public:
  /* Add new elem function */
  void addElem(GraphElem &NewElem)
  {
    NewElem.setId(_elements.size());
    _elements.push_back(NewElem);

    for (auto a : _matrix)
      a.push_back(false);

    std::vector<bool> newVec(_elements.size());
    _matrix.push_back(newVec);
  } /* End of 'addElem' function */

  /* Add new link function */
  void addLink(const int Id1, const int Id2)
  {
    _matrix[Id1][Id2] = true;
    _matrix[Id2][Id1] = true;
  } /* End of 'addLink' function */

  WeightT getWeight(int start, int end) const 
  {
    return _elements[start].getWeight(_elements[end]);
  }
  const std::vector<GraphElem>& getElements() const 
  {
    return _elements;
  }
private:
  /* Array of elements */
  std::vector<GraphElem> _elements;

  /* Adjancency matrix */
  std::vector<std::vector<bool>> _matrix;
}; /* End of 'Graph' class */

/* END OF 'graph.h' FILE */
