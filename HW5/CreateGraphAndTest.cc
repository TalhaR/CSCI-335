// Author: Talha Rahman
// descrption: Reads two files. One graph.txt file and an adjacencyquery file
//             Creates a graph from the Graph.txt file. Next checks if any 
//             Of the vertices in the adjacencyquery file are connected to each 
//             other

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

#include "graph.h"

using namespace std;

int graphTestDriver(int argc, char **argv) {
  //Begin your code here. Feel free to add any helper functions or classes you need,
  //as long as we only have to call this function to run the specified assignment. 
  ifstream graphFile{argv[1]}, adjQueryFile{argv[2]};
  
  if (graphFile.fail() || adjQueryFile.fail()) {
    cerr << "File(s) could not be opened\n";
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
  
  // Adjacency List Stuff
  
  size_t x1, x2;
  
  while (adjQueryFile >> x1 >> x2) {
    cout << x1 << " " << x2 << ": ";
    if (graph.checkEdge(x1, x2) != -1) {
      cout << "connected " << graph.checkEdge(x1, x2);
    } else {
      cout << "not_connected";
    }
    
    cout << "\n";
  }

  return 0;
}

int main(int argc, char **argv) {
  if (argc != 3) {
    cout << "Usage: " << argv[0] << " <GRAPH_File>" << "<ADJACENCY_QUERYFILE>" << endl;
    return 0;
  }

  graphTestDriver(argc, argv);

  return 0;
}