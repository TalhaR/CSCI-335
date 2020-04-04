Homework Question 1-0: 
    File: quadratic_probing.h 
    
    I finished all parts. Added methods and functionality into quadratic_probing
    to print out information including the number of elements, size of the table,
    number of collisions, load factor, average collisions and lastly a way to 
    search for certain words in the hash_table and figure out the number of probes
    it took to either find or not find that thing in the table
    
Question 1-1:
    File: linear_probing.h
    
    I finished all parts. This was extremely easy. I just had to copy paste
    the quadratic_probing.h file over to another file. Then I went into the 
    FindPos() function and modified it to do linear probing. Which was super
    easy because you just change the current position by 1 instead of anything
    fancy.
    
Question 1-2:
    File: double_hashing.h
    rValue: 83
    
    I finished all parts. This was also fairly straightforward. I copied 
    over quadratic_probing.h again. I then duplicated InternalHash and 
    modified it to have the rVal apart of it with the formula that was 
    given. At first I had it as a static 83 to test but the modified it 
    to allow for the user to pass in one. To accomodate this I added a 
    private variable to hold the rVal and then modified the constructors to 
    initialize it based on what was passed in by the user. Then I modified 
    create_and_test_hash.cc to allow for a 5th argument for an rValue. 
    
    I went with a rValue of 83 because it was a good prime number that was 
    less than the size of the array. Gave me good results collisions wise.
    
Question 1-3:
    File: spell_check.cc
    
    I finished all parts. I enjoyed this part the most. Felt like a puzzle.
    I mostly did the same things as the start of my create_and_test_hash.cc file
    which was just reading in input and adding the words from the dictionary into
    the hash_table. I decided to go with the quadratic_probing implementation of 
    the hash_table because it was working well for me with regards to collisions. 
    I then parsed the document file and removed special characters at the front and 
    back first. Then made everything lower case. Had to consult the cpp reference website
    a few times here. Then I printed out if it was incorrect or correct. Then 
    worked through the 3 different cases. Starting with B then A and then C because 
    part C made me remove an element and then add it somewhere else, which is a 
    combination of what part A and B had me doing. 