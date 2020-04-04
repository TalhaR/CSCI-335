/**
 * @author Talha Rahman
 *  summmary: program takes in a two files. One that acts as a dictionary
 *  and one that is a text file to be examined and spell-checked. The program
 *  has a hashtable that uses quadratic probing. After adding all the words from
 *  the dictionary into the hashtable, the program will start checking each word
 *  in the other document file. If a word is incorrect, it will check to see if 
 *  the word could possibly be made correct. Either by adding one letter somewhere,
 *  removing one letter, or by swapping adjacent letters. It will print this out
 *  along side if a word is incorrect or just prints out if a word is correct.
 */
#include "quadratic_probing.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int testSpellingWrapper(int argument_count, char** argument_list) {
  const string document_filename(argument_list[1]);
  const string dictionary_filename(argument_list[2]);

  fstream docFile{document_filename}, dicFile{dictionary_filename};
  
  if (docFile.fail() || dicFile.fail()) {
    std::cerr << "Can not open files\n";
    exit(1);
  }

  // Call functions implementing the assignment requirements.
  HashTable<string> hash_table; // hash_table that uses quadratic probing
  string wordInFile;
  
  // fills hash_table with words
  while(getline(dicFile, wordInFile)) {
    hash_table.Insert(wordInFile);
  }
  
  // checks docFile words with words in HashTable
  while (docFile >> wordInFile) {
    if (!isalnum(wordInFile.at(wordInFile.size()-1))) {
      wordInFile.pop_back(); // removes special char at back
    }
    if (!isalnum(wordInFile.at(0))) {
      wordInFile.replace(0,1,""); // removes special char at front
    }
    
    for(char& c : wordInFile) {
      c = tolower(c); // makes every letter lowercase
    }
    
    cout << wordInFile << " is ";
    
    if (!hash_table.Contains(wordInFile)) {
      cout << "INCORRECT\n";
      
      string foundWord = ""; // holds a word that was already found so no printing repeats
      for(char c = 'a'; c <= 'z'; ++c) { // case A
        for(int i = 0; i <= wordInFile.size(); ++i){
          string strCopy{wordInFile};
          strCopy.insert(i, string{c}); // adds 1 char into string
          
          if (hash_table.Contains(strCopy) && strCopy != foundWord) { // checks if new string is a word
            cout << "** " << wordInFile << " -> " << strCopy << " ** case A\n";
            foundWord = strCopy;
          }
        }
      }
      
      for(int i = 0; i < wordInFile.size(); ++i){ // case B
        string strCopy{wordInFile};
        strCopy.replace(i, 1, ""); // removes 1 char at a time
        
        if (hash_table.Contains(strCopy) && strCopy != foundWord) { // checks if new string is a word
          cout << "** " << wordInFile << " -> " << strCopy << " ** case B\n";
          foundWord = strCopy;
        }
      }
      
      for(int i = 0; i < wordInFile.size() - 1; ++i) { // case C
        string strCopy{wordInFile};
        strCopy.replace(i, 1, ""); // removes char at i
        strCopy.insert(i+1, string{wordInFile.at(i)}); // adds removed char into new position
        
        if (hash_table.Contains(strCopy) && strCopy != foundWord){
          cout << "** " << wordInFile << " -> " << strCopy << " ** case C\n";
          foundWord = strCopy;
        }
      }
    } else {
      cout << "CORRECT\n";
    }
  }
}

// Sample main for program spell_check.
// WE WILL NOT USE YOUR MAIN IN TESTING. DO NOT CODE FUNCTIONALITY INTO THE MAIN.
// WE WILL DIRECTLY CALL testSpellingWrapper. ALL FUNCTIONALITY SHOULD BE THERE.
// This main is only here for your own testing purposes.
int main(int argc, char **argv) {
  if (argc != 3) {
    cout << "Usage: " << argv[0] << " <document-file> <dictionary-file>" << endl;
    return 0;
  }
  
  testSpellingWrapper(argc, argv);

  return 0;
}
