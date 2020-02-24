// <Your name>
// Main file for Part2(a) of Homework 2.

#include "avl_tree.h"
// You will have to add #include "sequence_map.h"

#include <iostream>
#include <string>
using namespace std;

namespace {

// @db_filename: an input filename.
// @a_tree: an input tree of the type TreeType. It is assumed to be
//  empty.
template <typename TreeType>
void QueryTree(const string &db_filename, TreeType &a_tree) {
  // Code for running Part2(a)
  // You can use public functions of TreeType. For example:
  // a_tree.insert(10);
  // a_tree.printTree();
  
  std::ifstream infile(db_filename);
  
  if (infile.fail()) {
    std::cerr << "Can not open file\n";
    exit(1);
  } 
  
  string db_line;
  
  // using this for loop to skip over first 10 lines
  // because the actual data starts on line 11
  for(short s = 0; s < 10; s++) {
    getline(infile, db_line);
  }
  
  while (getline(infile, db_line)) {
    string an_enz_acro;
    
    
    
    for(string::iterator itr = db_line.begin(); itr != db_line.end(); itr++) {
      
    }
    
    
  }
  
  
  
  infile.close();
}

}  // namespace

int
main(int argc, char **argv) {
  if (argc != 2) {
    cout << "Usage: " << argv[0] << " <databasefilename>" << endl;
    return 0;
  }
  const string db_filename(argv[1]);
  cout << "Input filename is " << db_filename << endl;
  // Note that you will replace AvlTree<int> with AvlTree<SequenceMap>
  AvlTree<int> a_tree;
  QueryTree(db_filename, a_tree);
  return 0;
}
