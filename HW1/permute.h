/**
 * @author Talha Rahman
 *  Date: 2/10/20
 *  Class: CSCI-335
 *  Program Description: Program meant to produce all permutations of a string
 *      printing all possible permutations to std::cout. 
*/
#include <iostream> 

/**
 * @param ch1 char to be swapped
 * @param ch2 char to be swapped
 * @post swaps ch1 and ch2 
*/
void swap(char& ch1, char& ch2) {
    char tmp = ch1;
    ch1 = ch2;
    ch2 = tmp;
}

/**
 @param str string to be permuted
 @param low lower-bound position in string to start swapping from
 @param high upper-bound position in string to end swapping at 
 @post prints all permutations of the string str
*/
void permute(const std::string str, int low, int high) {
    std::string str_ = str; // creates a mutable string copy of str to allow for swapping of letters
    if (low == high) {
        std::cout << str << "\n";
    } else {
        for (int i = low; i <= high; ++i) {
            swap(str_[low], str_[i]); // swaps char at pos low with positions above
            
            permute(str_, low + 1, high); // recursive call to swap remaining substrings
        }
    }
}

/**
 @param str string to be permuted
 @post prints all permutations of the string str
*/
void permute(const std::string str) {
    permute(str, 0, str.size()-1); // calls helper function 
}