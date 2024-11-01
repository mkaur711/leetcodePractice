#include <vector>

class Solution {
public:
    std::vector<int> findDiagonalOrder(std::vector<std::vector<int>>& mat) {
        if (mat.empty() || mat[0].empty()) return {};

        int m = mat.size();     // Number of rows
        int n = mat[0].size();  // Number of columns
        std::vector<int> result;
        result.reserve(m * n);  // Pre-allocate result size for efficiency
        int row = 0, col = 0;
        
        // Loop through each element until we've visited all elements
        for (int i = 0; i < m * n; i++) {
            result.push_back(mat[row][col]);
            
            // Moving upwards-right
            if ((row + col) % 2 == 0) { 
                if (col == n - 1) {       // Hit right boundary
                    row++;
                } else if (row == 0) {    // Hit top boundary
                    col++;
                } else {
                    row--; col++;
                }
            } 
            // Moving downwards-left
            else { 
                if (row == m - 1) {       // Hit bottom boundary
                    col++;
                } else if (col == 0) {    // Hit left boundary
                    row++;
                } else {
                    row++; col--;
                }
            }
        }
        
        return result;
    }
};
