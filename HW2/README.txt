You will use this exact Makefile for your Homework 2. If you need to change it, please consult with me first.

You can compile everything by typing 

make clean
make all

You can compile one program individually by just typing make <Program Name>, for example

make query_tree

By typing 

make clean

You delete all .o files and executables.

--Note that file avl_tree_modified.h is not provided.

Homework Question 1: 
    File: HW2Q1.cc
  
    I completed all parts.
    I created a global function that returns the iterator containing the 
    first occurrence of x in the range of start - end. If x is not found.
    then end will be returned.

Homework Question 2-1:
    File: sequence_map.h 
    
    I completed all parts
    I created a SequenceMap class that maps a recognition sequence 
    to some enzyme_acronyms. I added a parameterized constructor,
    overloaded the '<' and '<<' operators and lastly created a Merge
    function that will combine the enzyme_acronyms of two different
    SequenceMaps if the recognition sequences are the same.
    
    
Homework Question 2-2a:
    File: query_tree.cc, avl_tree_p2a.h
    
    I completed all parts
    I parsed the data in the rebase210.txt file and created
    SequenceMap objects in the avl tree that were based on the 
    inputed parsed. Finally, I ask the user for soem recognition 
    sequences and print the coresponding enzyme_acronyms if they 
    exist within the tree.
    
    The hardest part was reading input I fogot that it was possible 
    to use getline(file, storingLocation, '/') to get input until the 
    the next '/' is found, but once I found that out online then it made
    the parsing a lot easier.
    
Homework Question 2-2b:
    File: test_tree.cc, avl_tree_p2b.h
    
    I completed all parts
    I made a search tree just like part 2a. Then printed out the requested
    information. Such as the number of nodes, average depth, the number 
    of recursion calls for searching and for removal and then the state of 
    the tree after removing every other sequence that was in the Sequence file
    from the tree. 
    
    The hardest part for me was counting the recursion calls for part "5b" 
    My final output at first was "~9.18" but expected was "9.11". I had to 
    recheck my algorithm for counting quite a bit. Eventually I got it to be 
    within the delta by only counting successful removals.
    
Homework Question 2-2c:
    File: test_tree_mod.cc, avl_tree_p2c.h
    
    I completed all parts.
    The single rotations were fairly straightforward but the 
    double rotations were quite confusing. Once I drew out pictures 
    then it made more sense.

