/**
 * @author Talha Rahman
 * date: 2/22/20
 * class: CSCI-335
 * Program Description: Class that contains a sequence of 2D points 
 *  points are stored in a 2D matrix. Can access and modify points 
 *  in sequence. ALong with adding with other sequences of type Points2D.
 */

#pragma once 

#include <string>
#include <vector>
using std::string;

class SequenceMap {
    public:
        SequenceMap() = default;
        ~SequenceMap() = default;
        
        SequenceMap(const SequenceMap& rhs) = default;
        SequenceMap& operator=(const SequenceMap& rhs) = default;
        
        SequenceMap(SequenceMap&& rhs) = default;
        SequenceMap& operator=(SequenceMap&& rhs) = default;
        
        SequenceMap(const string& a_rec_seq, const string& an_enz_acro) 
            : recognition_sequence_(a_rec_seq), enzyme_acronyms_{an_enz_acro} {}
            
        bool operator<(const SequenceMap &rhs) const {
            if (recognition_sequence_ < rhs.recognition_sequence_) {
                return true;
            }
            return false;
        }
        
        friend std::ostream& operator<<(std::ostream& out, const SequenceMap& someSequenceMap);
        
        void Merge(const SequenceMap& other_sequence) {
            recognition_sequence_ += other_sequence.recognition_sequence_;
        }
        
    private:
        string recognition_sequence_;
        std::vector<string> enzyme_acronyms_;                
};