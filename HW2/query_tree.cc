// @author Talha Rahman
// Main file for Part2(a) of Homework 2.

#include "avl_tree.h"
// You will have to add #include "sequence_map.h"
#include "sequence_map.h"
#include "avl_tree_p2a.h"
#include "avl_tree_p2c.h"

#include <fstream>
#include <sstream>
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
  for(unsigned char c = 0; c < 10; ++c) {
    getline(infile, db_line);
  }
  
  // Reads the fine line-by-line
  while (getline(infile, db_line)) {
    string an_enz_acro;
    vector<string> recognition_sequences;
    stringstream db_line_stream{db_line};
    
    // reads the first part of the db_line which is an
    // enzyme acronym and stores it in the an_enz_acro variable
    getline(db_line_stream, an_enz_acro, '/'); 
    string a_reco_seq = "";
    
    while(getline(db_line_stream, a_reco_seq, '/')) {
      // this if means we've reached the "//" at the end
      // of the rebase line, so we add a new SequenceMap object
      // to the tree and then skip to next line
      if (a_reco_seq.empty()) {
        for (string& sequence : recognition_sequences) {
          SequenceMap new_sequence_map{sequence, an_enz_acro};
          a_tree.insert(new_sequence_map);
        }
        
        recognition_sequences.clear(); // clears vector to use for next enzyme
        
        db_line_stream >> a_reco_seq;
        continue;
      }
      // pushes back each sequence read into a string vector for recognition sequences
      recognition_sequences.push_back(a_reco_seq);
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
  AvlTree<SequenceMap> a_tree;
  QueryTree(db_filename, a_tree);
  
  vector<string> inputs;
  string input1, input2, input3;
  cout << "enter 3 recognition sequences: ";
  cin >> input1 >> input2 >> input3;
  
  inputs.push_back(input1); 
  inputs.push_back(input2); 
  inputs.push_back(input3);
  
  for (int i = 0; i < 3; ++i){
    SequenceMap input_sequence_map(inputs[i], {});
    
    if(a_tree.contains(input_sequence_map)){ 
      cout << a_tree.find(inputs[i]) << "\n";
    } else { 
      cout << "Not Found\n"; 
    }
  }
  std::cout << "\n";
  
  return 0;
}
