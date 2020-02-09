/**
 * @author Talha Rahman
 * Class: CSCI-335
 * Program Description: Class that contains a sequence of 2D points 
 *  points are stored in a 2D matrix. Can access and modify points 
 *  in sequence. ALong with adding with other sequences of type Points2D.
 * 
 */

#ifndef CSCI335_HOMEWORK1_POINTS2_H_
#define CSCI335_HOMEWORK1_POINTS2_H_

#include <array>
#include <iostream>
#include <cstddef>
#include <string>
#include <sstream>

namespace teaching_project {
// Place comments that provide a brief explanation of the class,
// and its sample usage.
template<typename Object>
class Points2 {
 public:
  // Default "big five" -- you have to alter them for your assignment.
  // That means that you will remove the "= default" statement.
  //  and you will provide an implementation.

  // Zero-parameter constructor. 
  Points2() : size_(0), sequence_(new std::array<Object, 2>()) {}

  // Copy-constructor.
  /**
 * @param rhs another object of type Points2D to be copied from
 * @post copies the sequence and size of rhs and creates an identical
 *       object to it.
  */
  Points2(const Points2 &rhs) 
   : sequence_(new std::array<Object, 2>(*rhs.sequence_)), 
     size_(rhs.size_) {
    for (size_t i = 0; i < size_; ++i) {
      sequence_[i][0] = rhs.sequence_[i][0]; 
      sequence_[i][1] = rhs.sequence_[i][1]; 
    }
  }
  
  // Copy-assignment. If you have already written
  // the copy-constructor and the move-constructor
  // you can just use:
  // {
  // Points2 copy = rhs; 
  // std::swap(*this, copy);
  // return *this;
  // }
  /**
 * @param rhs another object of type Points2D to be copied from
 * @post assigns all attributes of rhs to an another existing Points2D object
  */
  Points2& operator=(const Points2 &rhs) {
    if (this != &rhs) {
      Points2 copy = rhs;
      std::swap(*this, copy);
    } 
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
  // Just use std::swap() for all variables.
  /**
 * @param rhs another object of type Points2D that will be losing it's data
 * @post all attributes of rhs will be transfered to an existing Points2D object
  */
  Points2& operator=(Points2 &&rhs) noexcept {
    if (this != &rhs) {
      std::swap(sequence_, rhs.sequence_);
      std::swap(size_, rhs.size_);
      
      // delete[] sequence_; // deletes any existing information 
      
      // sequence_ = rhs.sequence_;
      // size_ = rhs.size_;
      
      // rhs.sequence_ = nullptr;
      // rhs.size_ = 0;
    }
    return *this;
  }
  /**
 * Desctructor
 * @post deletes the sequence_ array that was allocated on the heap
  */
  ~Points2() {
    delete[] sequence_;
  }

  // End of big-five.

  // One parameter constructor.
  /**
 * @param item an object of type std::array<Object, 2> that will become a sequence of points
 * @post creates a Points2D object with a sequence of points created from the 
 *       item array that was passed in as a parameter.
  */
  Points2(const std::array<Object, 2>& item) 
    : size_(item.size()/2), sequence_(new std::array<Object, 2>()) {
      for (size_t i = 0; i < item.size(); ++i) {
        sequence_[0][i] = item[i]; 
      }
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
      sequence_[i][0] = token;
      input_stream >> token;
      sequence_[i][1] = token;
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
    if (location >= size_) abort();
    
    return *(sequence_+location);
  }

  /**
 * @param c1 A sequence
 * @param c2 A second sequence
 * @return the sum of c1 and c2. If sequences are different length
 *         append the result with the remaining part of the larger sequence
  */
  friend Points2 operator+(const Points2 &c1, const Points2 &c2) {
    Points2<Object> sum;
    sum.size_ = std::max(c1.size_, c2.size_);
    for(size_t i = 0; i < sum.size_; ++i) {
      sum.sequence_[i][0] = c1.sequence_[i][0] + c2.sequence_[i][0];
      sum.sequence_[i][1] = c1.sequence_[i][1] + c2.sequence_[i][1];
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
    for (size_t i = 0; i < some_points2.size(); ++i) {
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
