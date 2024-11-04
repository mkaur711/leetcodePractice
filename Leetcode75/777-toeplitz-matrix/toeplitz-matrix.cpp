class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        // Function to check if the diagonal starting from (row, col) has the same value
        auto isDiagonalUnivalue = [&](int row, int col) {
            int val = matrix[row][col];
            while (row < rows && col < cols) {
                if (matrix[row][col] != val) {
                    return false;
                }
                row++;
                col++;
            }
            return true;
        };

        // Check all diagonals starting from the first row
        for (int col = 0; col < cols; col++) {
            if (!isDiagonalUnivalue(0, col)) {
                return false;
            }
        }

        // Check all diagonals starting from the first column
        for (int row = 1; row < rows; row++) { // start from 1 to avoid checking (0,0) again
            if (!isDiagonalUnivalue(row, 0)) {
                return false;
            }
        }

        return true;
    }

};