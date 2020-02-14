You will use this exact Makefile for your Homework 1.
Failure to do so will result in deduction of points.

To compile on terminal type
  make clean
  make all

To delete executables and object file type
  make clean

To run:

./test_points2

^^In that case you will provide input from standard input.

To run with a given file that is redirected to standard input:

./test_points2 < test_input_file.txt


Homework Question 1: 
  File: Permute.h
  
  I completed all parts.
  I created a permute which calls an overloaded permute function 
  that will print all permutations of the given string that was passed
  in to the original function as a parameter

  The only challenging part was creating the logic for permuting the string.
  Gave me flash backs of 150, where I struggled quite a bit.

Homework Question 2: 
  File: points2.h
  
  Part 1:
    I completed all parts.
    I implemented all of the "Big 5" along with overloading the "<<" operator.
    I mostly followed the suggested comments for how to go about implementing 
    the "Big 5". 
    
    However, I found that the suggested implementation for the 
    move-assignment operator to be confusing. The comment suggests to simply 
    "use std::swap() for all variables" and the slide 39 for Lecture 2, also 
    does the same thing. However, this method is more of a "swap" method rather 
    than a "move". If the object receiving the data is non-empty then it will 
    swap it's data with the object it is receiving the data from. The way to avoid
    this would be to delete the data of the receiving object first. But we were 
    given an expected output that even reflects a "swap" instead of a "move" in which
    one object would be depleted of all its data.
    
    A major hurdle I had was with the accessing of the 2D array. I had not used the
    std::array class so I was not completely sure how to go about doing a lot of things 
    in relation to it. But after reading the documentation online, it started to make sense
    I also visited the discussion board on BlackBoard, which cleared somethings up.
  
  Part 2:
    I completed all parts.
    I overloaded the "[]" and "+" operators. 
    
    A challenge I had was with returning the correct value for the "[]" operator
    the return value is of type const std::array<Object, 2>&, but I was initially 
    just returning the value at that point inside (of type int or double). 
    The logic for adding the two sequences together was also a bit challenging. 
    I did not know what to do when the two sequences were of different lengths
    then I checked the discussion board on BlackBoard and there was an explanation for 
    what to do, which was helpful.  
    
    
  Instructions to run:
    Permute.h:
      import as a header file into a separate c++ file with main function
      call the permute(std::string str) method to print all permutations of 
      string str.
      
    Points2.h:
      if makefile is present, call make all
      then do "test_points2 < test_input_file.txt" 
      the contents of test_input_file.txt may be changed to test different sequences
      
    
    