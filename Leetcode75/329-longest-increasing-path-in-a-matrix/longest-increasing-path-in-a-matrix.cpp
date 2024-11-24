class Solution {
public:
    // Helper function for DFS with memoization
int dfs(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>& memo, int m, int n) {
    if (memo[i][j] != -1) return memo[i][j]; // Return cached result

    int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int maxLength = 1; // Minimum path length is 1 (current cell)

    for (auto& dir : directions) {
        int x = i + dir[0], y = j + dir[1];
        if (x >= 0 && x < m && y >= 0 && y < n && matrix[x][y] > matrix[i][j]) {
            maxLength = max(maxLength, 1 + dfs(matrix, x, y, memo, m, n));
        }
    }

    memo[i][j] = maxLength; // Cache the result
    return maxLength;
}

int longestIncreasingPath(vector<vector<int>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) return 0;

    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> memo(m, vector<int>(n, -1)); // Memoization table
    int result = 0;

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            result = max(result, dfs(matrix, i, j, memo, m, n)); // Explore each cell
        }
    }

    return result;
}
};