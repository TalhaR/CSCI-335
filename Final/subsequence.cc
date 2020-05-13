#include <iostream>
#include <string>
#include <vector>
using namespace std;

int subsequence_driver(int argc, char **argv) {
    //Please place all functionality in here instead of the main.
    //Feel free to make any functions or objects you wish, as long as we only call this function.
    string str1{argv[1]};
    string str2{argv[2]};
    
    const size_t ROWS{str1.size()}, COLUMNS{str2.size()};
    
    // Creating a matrix for tabulation.
    // The rows represent elements from str1. The columns represent elements from str2
    // We will be populating it with numbers that represent the number of common letters
    // seen thus far.
    // Row 0 and Column 0 is all 0's to represent the empty strings. The empty string
    // can't have anything in common with anything else so all elements are 0's
    vector<vector<size_t>> matrix(ROWS + 1, vector<size_t>(COLUMNS + 1)); // Creates a Matrix of str1.size()+1 * str2.size()+1
    
    // Goal of these nested for-loops is to go through each position in 
    // the matrix and populate it with a number to represent the number of common letters
    // detected thus far. For instance, the first ROW might represent 'a' from str1 and we
    // then go through each column aka elements of str2 to see if any match 'a', if they do
    // we take the number above and to the left and increase by one, otherwise we take the 
    // max of the previous column and the row above that position and just leave it as that.
    
    for (size_t i = 1; i <= ROWS; ++i) {             // Goes through elements of str1
        for (size_t j = 1; j <= COLUMNS; ++j) {         // Goes through elements of str2
            if (str1[i - 1] == str2[j - 1]) {               // If an element of str1 is found in str2
                matrix[i][j] = matrix[i - 1][j - 1] + 1;    // Add one to the previous max number of 
            } else {                                        // common characters detected
                matrix[i][j] = max(matrix[i - 1][j],        // the element in str1 is not in str2 so
                                    matrix[i][j - 1]);      // we just take the max of the left and top numbers
            } 
        }
    }
    
    string longestSubStr = "";
    size_t firstVal = matrix[ROWS][0];
    
    // This for loop goes through the last row of the matrix
    // Each time one of the columns changes in this row
    // the associated letter in the str2 was foundin str1. 
    // For instance: 
    /**      x a a b e
     *     _ _ _ _ _ _
     *   | 0 0 0 0 0 0
     * a | 0 0 1 1 1 1
     * b | 0 0 1 1 2 2
     */
    // In this example at matrix[2][2] the number 
    // changes to 1 so that means we found the first 
    // 'a' from str2 in str1. And when we increase to 
    // 2 at matrix[2][4] we find the 'b' from str2
    // in str1. So whenever we see the increase we can just 
    // add the character at str[i] to a string to see what the 
    // longest substring sequence is
    
    for(size_t i = 1; i <= COLUMNS; ++i) {
        if (matrix[ROWS][i] != firstVal) {
            longestSubStr += str2[i-1];
            firstVal = matrix[ROWS][i];
        }
    }

    cout << matrix[ROWS][COLUMNS] << "\n";
    cout << longestSubStr << "\n";
}

int main(int argc, char **argv) {
    if (argc != 3) {
		cout << "Usage: " << argv[0] << "<word_a>" << "<word_b>" << endl;
		return 0;
    }

    subsequence_driver(argc, argv);

    return 0;
}