// Author: Talha Rahman
// Descrption: reads from a Graph.txt file to make a graph 
// and will print out all the possible ways to visit another vertex
// in the graph using dijsktra's algorithm

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

#include "graph.h"

using namespace std;

int pathfindDriver(int argc, char **argv) {
  //Begin your code here. Feel free to add any helper functions or classes you need,
  //as long as we only have to call this function to run the specified assignment.
  ifstream graphFile{argv[1]};
  
  if (graphFile.fail()) {
    cerr << "File could not be opened\n";
    exit(0);
  }
  
  // do something to parse the Graph File Here
  string lineFromFile;
  
  getline(graphFile, lineFromFile);
  
  size_t numOfVertices = stoi(lineFromFile);
  
  Graph graph(numOfVertices);
  
  while(getline(graphFile, lineFromFile)) {
    stringstream ss{lineFromFile};
    
    size_t index, vertex;
    double weight;
    
    ss >> index;
    
    while (ss >> vertex >> weight) {
      graph.addEdge(index, vertex, weight);
    }
  }
  
  int startVertex{stoi(argv[2])};
  
  for(size_t i = 1; i <= numOfVertices; ++i) {
    graph.dijkstras(startVertex, i);
    
  }

  return 0;
}

int main(int argc, char **argv) {
  if (argc != 3) {
    cout << "Usage: " << argv[0] << " <GRAPH_FILE>" << "<STARTING_VERTEX>" << endl;
    return 0;
  }

  pathfindDriver(argc, argv);

  return 0;
}