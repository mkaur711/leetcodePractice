class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> memo(m, vector<int>(n, -1));  // Memoization table
        
        int maxPath = 0;
        // Traverse each cell in the matrix
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                maxPath = max(maxPath, dfs(matrix, memo, i, j));  // Update max path length
            }
        }
        return maxPath;
    }
    
private:
    // Helper function for DFS with memoization
    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& memo, int i, int j) {
        if (memo[i][j] != -1) return memo[i][j];  // Return cached result if exists

        int m = matrix.size();
        int n = matrix[0].size();
        int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int maxLength = 1;  // Initialize path length for this cell
        
        // Explore all four directions
        for (auto& dir : directions) {
            int x = i + dir[0], y = j + dir[1];
            // Check if the new cell is within bounds and increasing
            if (x >= 0 && x < m && y >= 0 && y < n && matrix[x][y] > matrix[i][j]) {
                maxLength = max(maxLength, 1 + dfs(matrix, memo, x, y));  // Update max path
            }
        }
        
        memo[i][j] = maxLength;  // Cache the result for this cell
        return maxLength;
    }
    
};