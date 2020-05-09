#ifndef STUDENT_GRAPH
#define STUDENT_GRAPH

#include "binary_heap.h"
#include <limits>
#include <unordered_map>
#include <unordered_set>
#include <stack>

// Author: Talha Rahman
// Descrption: A graph class which contains vertices that hold an adjacencylist
//             Can use dijsktra's algorithm to find the shortest path to another 
//             Vertex inside of the Graph

//This file is for your graph implementation.
//Add everything you need in between the "ifndef and "endif" statements.
//Do not put anything outsode those statements

class Graph {
  private:
    struct Vertex {
      vector<pair<Vertex*, double>> adjList; // holds a list of pairs
                                              // each Vertex has an associated weight
      
      size_t vertexNum;
      double totalWeight;

      Vertex(size_t i) : vertexNum(i), totalWeight(numeric_limits<int>::max()) {}
      
      void addEdge(Vertex* vertex, size_t num, double weight) {
        vertex->vertexNum = num;
        vertex->totalWeight = weight;
        adjList.push_back(make_pair(vertex, weight));
      }
    };
      
    vector<Vertex*> vertices; 
  
  public:
    Graph(size_t size) {
      for(size_t i = 0; i < size; ++i) {
        vertices.push_back(new Vertex(i + 1));
      }
    }
    
    void addEdge(size_t start, size_t end, double weight) {
      Vertex* startVertex = vertices[start - 1];
      Vertex* endVertex = vertices[end - 1];
      
      startVertex->addEdge(endVertex, end, weight);
    }
    
    double checkEdge(size_t vertex1, size_t vertex2) {
      auto list = vertices[vertex1 - 1]->adjList;
      
      for(auto& pair : list) {    // goes through adjList to see if it exists
        if (pair.first->vertexNum == vertex2) {
          return pair.second;     // returns the associated weight if found to be adjacent
        }
      }
      return -1;                  // returns -1 if not found
    }
    
    void dijkstras(size_t start, size_t end) {
      BinaryHeap<pair<double, int>> queue; 
      Vertex* origin = vertices[start];
      
      queue.insert(make_pair(0.0, start));
      
      unordered_map<int, pair<int, double>> path;
      unordered_set<int> visitedVertices;        
      
      while(!queue.isEmpty()) {
        int currentVertex = queue.findMin().second; 
        double currentWeight = queue.findMin().first;
        queue.deleteMin(); // pop off
        
        if (currentVertex == end) { // true if find the route
          stack<int> stack;  // using to reverse the order of nodes
          
          cout << end << ": ";
          
          while (currentVertex != start) {        // backtracking from end node
            stack.push(currentVertex);            // to original node while adding to stack
            currentVertex = path[currentVertex].first;
          }
          
          stack.push(currentVertex);
          
          while (!stack.empty()) {                // once popped off the stack
            cout << stack.top() << " ";           // the order will be correct
            stack.pop();
          }
          
          cout << "cost: " << currentWeight << "\n";
          return;
        }  
      
        // if the Vertex was already visited escape
        if (visitedVertices.find(currentVertex) != visitedVertices.end()) continue;
        
        visitedVertices.insert(currentVertex);
        
        for(size_t i = 1; i <= vertices.size(); ++i) {
          if (checkEdge(currentVertex, i) != -1) {
            double dist = checkEdge(currentVertex, i) + currentWeight;
            queue.insert(make_pair(dist, i));
            
            if (path.find(i) != path.end()) {
              if (path[i].second > dist) { 
                path[i] = make_pair(currentVertex, dist);
              }
            } else 
              path[i] = make_pair(currentVertex, dist);
          }
        }
      }
      cout << end << ": not_possible\n"; 
    }
    
};

#endif