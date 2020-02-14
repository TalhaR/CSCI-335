/**
 * @author Talha Rahman
 * Date: 2/10/20
 * Class: CSCI-335
 * Program Description: Class that contains a sequence of 2D points 
 *  points are stored in a 2D matrix. Can access and modify points 
 *  in sequence. ALong with adding with other sequences of type Points2D.
 */

#ifndef CSCI335_HOMEWORK1_POINTS2_H_
#define CSCI335_HOMEWORK1_POINTS2_H_

#include <array>
#include <iostream>
#include <cstddef>
#include <string>
#include <sstream>

namespace teaching_project {
template<typename Object>
class Points2 {
 public:
  // Zero-parameter constructor. 
  Points2() : size_(0), sequence_(new std::array<Object, 2>[2]) {}

  // Copy-constructor.
  /**
 * @param rhs another object of type Points2D to be copied from
 * @post copies the sequence and size of rhs and creates an identical
 *       object to it.
  */
  Points2(const Points2 &rhs) 
   : sequence_(new std::array<Object, 2>[rhs.size_*2]), 
     size_(rhs.size_) {
    for(size_t i = 0; i < rhs.size_; ++i){
      sequence_[i][0] = rhs.sequence_[i][0];
      sequence_[i][1] = rhs.sequence_[i][1];
    }
  }
  
  // Copy-assignment. If you have already written
  // the copy-constructor and the move-constructor
  /**
 * @param rhs another object of type Points2D to be copied from
 * @post assigns all attributes of rhs to an another existing Points2D object
  */
  Points2& operator=(const Points2 &rhs) {
    Points2 copy = rhs;
    std::swap(*this, copy);
    return *this;
  }

  // Move-constructor. 
  /**
 * @param rhs another object of type Points2D that will be losing it's data
 * @post all attributes of rhs will be transferred to a new Points2D object
  */
  Points2(Points2 &&rhs) noexcept : sequence_(rhs.sequence_), size_(rhs.size_) {
    rhs.sequence_ = nullptr;
    rhs.size_ = 0;
  }

  // Move-assignment.
  /**
 * @param rhs another object of type Points2D that will be losing it's data
 * @post all attributes of rhs will be transfered to an existing Points2D object
  */
  Points2& operator=(Points2 &&rhs) noexcept {
    if (this != &rhs) {
      std::swap(sequence_, rhs.sequence_);
      std::swap(size_, rhs.size_);
    }
    return *this;
  }
  /**
 * Desctructor
 * @post deletes the sequence_ array that was allocated on the heap
  */
  ~Points2() {
    if (sequence_ != nullptr) {
      delete[] sequence_;
      sequence_ = nullptr;
      size_ = 0;
    }
  }

  // End of big-five.

  // One parameter constructor.
  /**
 * @param item an object of type std::array<Object, 2> that will become a sequence of points
 * @post creates a Points2D object with a sequence of points created from the 
 *       item array that was passed in as a parameter.
  */
  Points2(const std::array<Object, 2>& item) 
    : size_(item.size()), sequence_(new std::array<Object, 2>[2]) {
      sequence_[0][0] = item[0]; 
      sequence_[0][1] = item[1]; 
    }

  // Read a chain from standard input.
    /**
 * @post reads in information from the user to create a sequence of points
 *       for the Points2D object.
  */
  void ReadPoints2() {
    // Part of code included (without error checking).
    std::string input_line;
    std::getline(std::cin, input_line); 
    std::stringstream input_stream(input_line);
    if (input_line.empty()) return;
    // Read size of sequence (an integer).
    int size_of_sequence;
    input_stream >> size_of_sequence;
    // Allocate space for sequence.
    // Add code here.
  
    size_ = size_of_sequence;
    
    Object token;
    for (size_t i = 0;input_stream >> token; ++i) {
      // fills in sequence_ as the user gives in coordinates
      sequence_[0][i] = token;
    }
  }
  /**
 * @return size of sequence_
  */
  size_t size() const {
    return size_;
  }

  // const version.
  // abort() if out-of-range.
    /**
 * @param location an index to a location in the sequence
 * @return the point at location
  */
  const std::array<Object, 2>& operator[](size_t location) const { 
    if (location >= size_ || location < 0) abort();
    
    // return *(sequence_+location);
    return sequence_[location];
  }

  /**
 * @param c1 A sequence
 * @param c2 A second sequence
 * @return the sum of c1 and c2. If sequences are different length
 *         append the result with the remaining part of the larger sequence
  */
  friend Points2 operator+(const Points2 &c1, const Points2 &c2) {
    const Points2* largerSquencePtr;
    const Points2* smallerSquencePtr;
    
    if (c1.size_ > c2.size_) {
      largerSquencePtr = &c1;
      smallerSquencePtr = &c2;
    } else {
      largerSquencePtr = &c2;
      smallerSquencePtr = &c1;
    }
    
    Points2 sum{*largerSquencePtr};
    
    for (size_t i = 0; i < smallerSquencePtr->size_; ++i) {
      sum.sequence_[i][0] += smallerSquencePtr->sequence_[i][0];
      sum.sequence_[i][1] += smallerSquencePtr->sequence_[i][1];
    }
    return sum;
  }

  // Overloading the << operator.
  /**
 * @param out console output 
 * @param some_points2 Object of Points2D with a sequence of points to be printed
 * @post prints out the sequence of points in some_points2 as (x, y)...
 * @return an object of std::ostream
  */
  friend std::ostream &operator<<(std::ostream &out, const Points2 &some_points2) {
    if (some_points2.size_ == 0) out << "()";
    for (size_t i = 0; i < some_points2.size_; ++i) {
      out << "(" << some_points2.sequence_[i][0] << ", " << some_points2.sequence_[i][1] << ") ";
    }
    out << "\n";
   
    return out;
  }
 
 private:
  // Sequence of points. 
  std::array<Object, 2> *sequence_;
  // Size of sequence.
  size_t size_;
};

}  // namespace teaching_project
#endif // CSCI_335_HOMEWORK1_POINTS2_H_
