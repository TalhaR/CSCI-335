/**
 * @author Talha Rahman
 *  Summary: added on to TestFunctionForHashTable to print 
 *           out releveant information about the hash_table(s)
 *           and to perform searches of the hash table for certain 
 *           words from a given file "query_words.txt"
 */

#include "quadratic_probing.h"
#include "linear_probing.h"
#include "double_hashing.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


template <typename HashTableType>
void TestFunctionForHashTable(HashTableType &hash_table, const string &words_filename, const string &query_filename) {
  hash_table.MakeEmpty();  

  std::ifstream wordsFile{words_filename}, queryFile{query_filename};
  
  if (wordsFile.fail() || queryFile.fail()) {
    std::cerr << "Can not open files\n";
    exit(1);
  }
  
  string inputLine;
  
  while(getline(wordsFile, inputLine)){
    hash_table.Insert(inputLine);
  }

  cout << "number_of_elements: " << hash_table.getSize() << endl;
  cout << "size_of_table: " << hash_table.getTableSize() << endl;
  cout << "load_factor: " << hash_table.getLoadFactor() << endl;
  cout << "collisions: " << hash_table.getCollisions() << endl;
  cout << "avg_collisions: " 
    << hash_table.getAverageCollisions() << endl;
  cout << "\n";
  
  while(getline(queryFile, inputLine)) {
    hash_table.clearCollisions();
    cout << inputLine << " ";
    
    if (!hash_table.Contains(inputLine)) {
      cout << "Not_";
    } 
    cout << "Found " << hash_table.getCollisions() + 1 << "\n";
    
  }
}

int testFunctionWrapper(int argument_count, char **argument_list) {
  const string words_filename(argument_list[1]);
  const string query_filename(argument_list[2]);
  const string param_flag(argument_list[3]);
  
  size_t rvalue = 83;
  
  if (argument_count == 5) {
    rvalue = atoi(argument_list[4]);
  }

  if (param_flag == "linear") {
    HashTableLinear<string> linear_probing_table;
    TestFunctionForHashTable(linear_probing_table, words_filename, query_filename);    
  } else if (param_flag == "quadratic") {
    HashTable<string> quadratic_probing_table;
    TestFunctionForHashTable(quadratic_probing_table, words_filename, query_filename);    
  } else if (param_flag == "double") {
    cout << "r_value: " << rvalue << "\n";
    HashTableDouble<string> double_probing_table{101, rvalue};
    TestFunctionForHashTable(double_probing_table, words_filename, query_filename);    
  } else {
    cout << "Unknown tree type " << param_flag << " (User should provide linear, quadratic, or double)" << endl;
  }
  return 0;
}

// Sample main for program create_and_test_hash.
// WE WILL NOT USE YOUR MAIN IN TESTING. DO NOT CODE FUNCTIONALITY INTO THE MAIN.
// WE WILL DIRECTLY CALL testFunctionWrapper. ALL FUNCTIONALITY SHOULD BE THERE.
// This main is only here for your own testing purposes.
int main(int argc, char **argv) {
  if (argc != 4 && argc != 5) {
    cout << "Usage: " << argv[0] << " <wordsfilename> <queryfilename> <flag>" << endl;
    return 0;
  }
  
  testFunctionWrapper(argc, argv);
  return 0;
}
