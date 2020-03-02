/**
 * @author Talha Rahman
 * date: 2/22/20
 * class: CSCI-335
 * Program Description: Class that contains a sequence recognition sequence
 *                      and a enzyme acronym
 */

#pragma once 

#include <string>
#include <vector>
#include <iostream>
using std::string;

class SequenceMap {
public:
    // default constructor & destructor
    SequenceMap() = default;
    ~SequenceMap() = default;
    // default copy and copy-assignment constructors
    SequenceMap(const SequenceMap& rhs) = default;
    SequenceMap& operator=(const SequenceMap& rhs) = default;
    // default move and move-assignment constructors
    SequenceMap(SequenceMap&& rhs) = default;
    SequenceMap& operator=(SequenceMap&& rhs) = default;
    
    /**
     * @param a_rec_seq string that contains a recognition sequence 
     * @param an_enz_acro string that contains an enzyme acronym
     * @post initializes an SequenceMap object with a recognition sequence
     *       and enzyme acronym equivalent to parameters 
     */
    SequenceMap(const string& a_rec_seq, const string& an_enz_acro) 
        : recognition_sequence_{a_rec_seq}, enzyme_acronyms_{an_enz_acro} {}
        
    /**
     * @param rhs object of type SequenceMap that will be compared 
     * @post compares this->recognition_sequence_ to rhs.recognition_sequence_
     */        
    bool operator<(const SequenceMap &rhs) const {
        return recognition_sequence_ < rhs.recognition_sequence_;
    }
    
    // Overloading the << operator.
    /**
     * @param out console output 
     * @param someSequenceMap Object of SequenceMap with enzyme acronyms to be printed
     * @post prints out the contents of the enzyme_acronyms_ vector
     * @return an object of std::ostream
     */    
    friend std::ostream& operator<<(std::ostream& out, const SequenceMap& someSequenceMap) {
        for(auto& str : someSequenceMap.enzyme_acronyms_) {
            std::cout << str << " ";
        }
        
        return out;
    }
    
    /**
     * @param other_sequence object of type SequenceMap whose enzyme_acronyms_ will be appended
     * @post appends other_sequence.enzyme_acronyms_ to this->enzyme_acronyms_ as long as 
     *       both SequenceMap objects have the same recognition_sequence_
     */   
    void Merge(const SequenceMap& other_sequence) {
        if (recognition_sequence_ != other_sequence.recognition_sequence_) {
            std::cerr << "Recognition sequences do not match\n";
            abort();
        }
        
        // if other_sequence.enzyme_acronyms_ is empty then return
        if (other_sequence.enzyme_acronyms_.empty()) return;
        
        for (auto& str : other_sequence.enzyme_acronyms_) {
            enzyme_acronyms_.push_back(str);
        }
    }
    
private:
    string recognition_sequence_;
    std::vector<string> enzyme_acronyms_;                
};