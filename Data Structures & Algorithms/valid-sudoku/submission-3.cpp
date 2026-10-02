#include <unordered_map>

// this is probably way too complicated but its what i came up with lmao

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
       // We can find a way to test one square and run this 9 times
       // maybe we make a hash map and add each num to it, then if it 
       // finds another of that same num in a square it returns false
       // we reset the hash map on each iteration using map.clear();

       // 1. we need to figure out how we go from a full row to narrowing
       // down each 3x3 box first. we know theres a pattern of say
       // i = 1st row, j = 2nd row, k = 3rd row.
       // i think we can just start them out at predetermined spots and move them all over
       // by 3 consistently until the grid is finished

       std::unordered_map<char, int> my_map; // char is num, int is count of num (int > 1 == dup). not actually needed

       int row1 = 0, row2 = 1, row3 = 2;
       bool end_flag = false;

       // now we need to search for the num inside the map
       // if there already return false, if not add it
       auto map_helper = [&](const char val) -> bool {
           if (val == '.') {
               return true;
           }

           auto it = my_map.find(val);
           if (it == my_map.end()) {
               my_map.emplace(val, 1);
               return true;
           }

           return false;
       };

       // just brute force every row and then every column
       int row = 0;
       while (row != 9) {
        for (int i = 0; i < 9; i++) {
            if (!map_helper(board[row][i])) {
            //std::cout << "Failed on row helper. Row: " << row << ". i: " << i << std::endl;
            return false;
                return false;
            }
        }

        my_map.clear();
        row++;
       }

       row = 0;

       int col = 0;
       bool loop = true;
       while (row != 9) {
        if (!map_helper(board[col][row])) {
            //std::cout << "Failed on column helper. Column: " << col << ". Row: " << row << std::endl;
            return false;
        }

        //std::cout << board[col][row] << std::endl;
        col++;

        if (col == 9) {
            col = 0;
            row++;
            my_map.clear();
        }
       }

       // when we reach the end of a row, we increase all row values by 3
       // this does one square. we want to move all index values over by 1
       // and start again, then when we hit the end (k == 9 for example), we
       // increment the row values by 3 and start again from 0 for the index values
       while (end_flag != true) {
        if (row3 == 8) {
            end_flag = true;
        }

        int i = 0, j = 0, k = 0;
        while (k < 9) {
            //std::cout << board[row1][i] << std::endl;
            //std::cout << board[row2][j] << std::endl;
            //std::cout << board[row3][k] << std::endl;

            if (!map_helper(board[row1][i]) ||
                !map_helper(board[row2][j]) ||
                !map_helper(board[row3][k])) {
                    //std::cout << "Failed on end_flag!" << std::endl;
                    return false;
                }

            i++; j++; k++;

            if (k == 3 || k == 6 || k == 9) {
                my_map.clear();
            }
        }

        row1 += 3;
        row2 += 3;
        row3 += 3;
       }

       return true;
    }
};
