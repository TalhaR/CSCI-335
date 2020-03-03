/**
 * @author Talha Rahman
 * date: 2/22/20
 * class: CSCI-335
 * Program Description: 
 */
// Main file for Part2(b) of Homework 2.

// You will have to add #include "sequence_map.h"
#include "sequence_map.h"
#include "avl_tree_p2b.h"

#include <string>
#include <fstream>
#include <sstream>
#include <math.h>
using namespace std;

namespace {

// @db_filename: an input database filename.
// @seq_filename: an input sequences filename.
// @a_tree: an input tree of the type TreeType. It is assumed to be
//  empty.
template <typename TreeType>
void TestTree(const string &db_filename, const string &seq_filename, TreeType &a_tree) {
  // Code for running Part2(b) 
  
  std::fstream infile{db_filename};
  
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
    string a_reco_seq;
    
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
        
        db_line_stream >> a_reco_seq; // gets rid of the last "/"
        continue;
      }
      // pushes back each sequence read into a string vector for recognition sequences
      recognition_sequences.push_back(a_reco_seq);
    }
  }
  
  infile.close();
  
  int total_nodes = a_tree.getNumberOfNodes();
  
  cout << "2: " << total_nodes << "\n";
  cout << "3a: " << (float)a_tree.getInternalPathLength() 
    / total_nodes << "\n";
  
  cout << "3b: " << ((float)a_tree.getInternalPathLength() 
    / total_nodes) /  log2(total_nodes) << "\n";
  
  // Reading from Sequences File
  ifstream seq_file{seq_filename};
  string input_sequence;
  float successful_queries{0}, recursive_search_calls{0};
  
  if (seq_file.fail()) {
    std::cerr << "Sequence File could not open\n";
    exit(2);
  }
  
  while (getline(seq_file, input_sequence)) {
    SequenceMap seq_map(input_sequence, {});
    if (a_tree.contains(seq_map)) {
      successful_queries++;
      recursive_search_calls += a_tree.getRecursiveCalls();
    }
  }
  seq_file.close();
  
  cout << "4a: " << successful_queries << "\n";
  
  cout << "4b: " << recursive_search_calls / successful_queries << "\n";
  
  // opens Sequence file again
  ifstream seq_file2{seq_filename};
  int remove_calls{0}, recursive_remove_calls{0};
  
  while(getline(seq_file2, input_sequence)) {
    SequenceMap seq_map{input_sequence, {}};
    
    
    // if(a_tree.contains(seq_map)) {
      remove_calls++;
      a_tree.remove(seq_map);
      recursive_remove_calls += a_tree.getRecursiveCalls();
    // }
    getline(seq_file2, input_sequence); // skips every other line
  }
  seq_file2.close();
  
  cout << "5a: " << total_nodes - a_tree.getNumberOfNodes() << "\n";
  cout << "5b: " << (float)recursive_remove_calls / remove_calls << "\n";
  
  total_nodes = a_tree.getNumberOfNodes();
  
  cout << "6a: " << total_nodes << "\n";
  cout << "6b: " << (float)a_tree.getInternalPathLength() / total_nodes << "\n";
  cout << "6c: " << ((float)a_tree.getInternalPathLength() 
    / total_nodes) /  log2(total_nodes) << "\n";

}

}  // namespace

int
main(int argc, char **argv) {
  if (argc != 3) {
    cout << "Usage: " << argv[0] << " <databasefilename> <queryfilename>" << endl;
    return 0;
  }
  const string db_filename(argv[1]);
  const string seq_filename(argv[2]);
  cout << "Input file is " << db_filename << ", and sequences file is " << seq_filename << endl;
  // Note that you will replace AvlTree<int> with AvlTree<SequenceMap>
  AvlTree<SequenceMap> a_tree;
  TestTree(db_filename, seq_filename, a_tree);

  return 0;
}
