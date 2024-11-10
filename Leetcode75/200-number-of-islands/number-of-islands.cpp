class Solution {
public:
void dfs(vector<vector<char>>& grid, int i, int j) {
    // Boundary and water check
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == '0')
        return;
    
    // Mark the current cell as visited
    grid[i][j] = '0';

    // Recursively visit all adjacent cells (up, down, left, right)
    dfs(grid, i - 1, j); // up
    dfs(grid, i + 1, j); // down
    dfs(grid, i, j - 1); // left
    dfs(grid, i, j + 1); // right
}

int numIslands(vector<vector<char>>& grid) {
    int islandCount = 0;

    // Traverse each cell in the grid
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            // If we encounter a '1' (unvisited land), it's a new island
            if (grid[i][j] == '1') {
                islandCount++;    // Increment the island count
                dfs(grid, i, j);  // Start DFS to mark the entire island
            }
        }
    }
    return islandCount;
}
};