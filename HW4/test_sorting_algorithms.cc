// Homework 4
// Testing Sorting Algorithms
// Talha Rahman

#include "Sort.h"
#include <chrono>
#include <iostream>
#include <fstream>
#include <functional>
#include <string>
#include <vector>
using namespace std;

// Test function that shows how you can time a piece of code.
// Just times a simple loop.

void TestTiming() {
  cout << "Test Timing" << endl;
  const auto begin = chrono::high_resolution_clock::now();
  // Time this piece of code.
  int sum = 0;
  for (int i = 1; i < 1000000; ++i) sum ++;
  // End of piece of code to time.
  const auto end = chrono::high_resolution_clock::now();    
  cout << chrono::duration_cast<chrono::nanoseconds>(end - begin).count() << "ns" << endl;
  cout << chrono::duration_cast<chrono::milliseconds>(end - begin).count() << "ms" << endl;

}

// Generates and returns random vector of size @size_of_vector.
vector<int> GenerateRandomVector(size_t size_of_vector) {
  srand(time(NULL)); // randomizes the seed
  
  vector<int> randomVec(size_of_vector); // initalizes a vector of size @size_of_vector
  
  for(auto& elem : randomVec) { // fills array with random numbers
    elem = rand() % size_of_vector;
  }
  
  return randomVec;
}

// Generate and returns sorted vecotr of size @size_of_vector
// If smaller_to_larger is true, returns vector sorted from small to large
// Otherwise returns vector sorted from large to small
vector<int> GenerateSortedVector(size_t size_of_vector, bool smaller_to_larger) {
  vector<int> sortedVec(size_of_vector); // initalizes a vector of size @size_of_vector
  
  if (smaller_to_larger) {
    size_t x = 0;
    for(auto& elem : sortedVec) { // fills array with increasing numbers
      elem = ++x;
    }
  } else {
    size_t x = INT32_MAX;
    for(auto& elem : sortedVec) { // fills array with decreasing numbers
      elem = --x;
    }
  }
  
  return sortedVec;
}

// Verifies that a vector is sorted given a comparator
template <typename Comparable, typename Comparator>
bool VerifyOrder(const vector<Comparable> &input, Comparator less_than) {
  for(size_t i = 1; i < input.size(); ++i) {
    if (less_than(input[i], input[i-1])) return false;
  }
  return true;
}

// Computes duration given a start time and a stop time in nano seconds
long long ComputeDuration(chrono::high_resolution_clock::time_point start_time, chrono::high_resolution_clock::time_point end_time) {
  return chrono::duration_cast<chrono::nanoseconds>(end_time - start_time).count();
}

/**
 * @param vec a vector 
 * @param less_than an object of type std::less or std::greater
 * @post tests various sorting functions on the vector and prints 
 *       how long it takes to complete those sorting methods.
 */
template <typename Comparable, typename Comparator>
void TestTiming(vector<Comparable>& vec, Comparator less_than) {
  vector<int> vec2{vec};      // creates a copy of vec for MergeSort
  vector<int> vec3{vec};      // creates a copy of vec for QuickSort
  vector<int> vec4{vec};      // creates a copy of vec for QuickSort2
  vector<int> vec5{vec};      // creates a copy of vec for QuickSort3
  
  cout << "Heapsort\n\n";
  auto start = chrono::high_resolution_clock::now();
  HeapSort(vec, less_than);
  auto finish = chrono::high_resolution_clock::now();
  
  cout << "Runtime: " << ComputeDuration(start, finish) << " ns\n";
  cout << "Verified: " << VerifyOrder(vec, less_than) << "\n\n";
  
  cout << "MergeSort\n\n";
  start = chrono::high_resolution_clock::now();
  MergeSort(vec2, less_than);
  finish = chrono::high_resolution_clock::now();
  
  cout << "Runtime: " << ComputeDuration(start, finish) << " ns\n";
  cout << "Verified: " << VerifyOrder(vec2, less_than) << "\n\n";
  
  cout << "QuickSort\n\n";
  start = chrono::high_resolution_clock::now();
  QuickSort(vec3, less_than);
  finish = chrono::high_resolution_clock::now();
  
  cout << "Runtime: " << ComputeDuration(start, finish) << " ns\n";
  cout << "Verified: " << VerifyOrder(vec3, less_than) << "\n\n";
  
  
  cout << "Testing Quicksort Pivot Implementations\n\n";
  
  cout << "Median of Three\n\n";
  
  // not testing again because the QuickSort method called above
  // uses the Median of Three implementation so I will just copy it over
  cout << "Runtime: " << ComputeDuration(start, finish) << " ns\n";
  cout << "Verified: " << VerifyOrder(vec3, less_than) << "\n\n";
  
  cout << "Middle\n\n";
  start = chrono::high_resolution_clock::now();
  QuickSort2(vec4, less_than);
  finish = chrono::high_resolution_clock::now();
  
  cout << "Runtime: " << ComputeDuration(start, finish) << " ns\n";
  cout << "Verified: " << VerifyOrder(vec4, less_than) << "\n\n";  
  
  cout << "First\n\n";
  start = chrono::high_resolution_clock::now();
  QuickSort3(vec5, less_than);
  finish = chrono::high_resolution_clock::now();
  
  cout << "Runtime: " << ComputeDuration(start, finish) << " ns\n";
  cout << "Verified: " << VerifyOrder(vec5, less_than) << "\n\n";
}

// Wrapper function to test different sorting algorithms
void sortTestingWrapper(int argc, char **argv) {
  const string input_type = string(argv[1]);
  const int input_size = stoi(string(argv[2]));
  const string comparison_type = string(argv[3]);
  if (input_type != "random" && input_type != "sorted_small_to_large" && input_type != "sorted_large_to_small") {
    cout << "Invalid input type" << endl;
    return ;
  }
  if (input_size <= 0) {
    cout << "Invalid size" << endl;
    return ;
  }
  if (comparison_type != "less" && comparison_type != "greater") {
    cout << "Invalid comparison type" << endl;
    return ;
  }

  cout << "Running sorting algorithms: " << input_type << " " << input_size << " numbers " << comparison_type << endl;
  
  vector<int> input_vector; // array to be filled and tested on
  
  if (input_type == "random") {
    // Generate random vector
    input_vector = GenerateRandomVector(input_size);
  } else {
    // Generate sorted vector.
    if (comparison_type == "less") {
      input_vector = GenerateSortedVector(input_size, true);
    } else {
      input_vector = GenerateSortedVector(input_size, false);
    }
  }
  
  // Calling other function to test timing of various sorting methods
  if (comparison_type == "less") {
    TestTiming(input_vector, less<int>{});
  } else {
    TestTiming(input_vector, greater<int>{});
  }
}

int main(int argc, char **argv) {
  if (argc != 4) {
    cout << "Usage: " << argv[0] << "<input_type> <input_size> <comparison_type>" << endl;
    return 0;
  }
  
  sortTestingWrapper(argc, argv);

  return 0;
}