class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        
        // Early exit if start or end is blocked
        if (grid[0][0] != 0 || grid[n - 1][n - 1] != 0) {
            return -1;
        }
        
        // 8 possible directions (horizontal, vertical, diagonal)
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, 
                                             {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
        
        // BFS queue storing (row, col, path_length)
        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = 1;  // Mark as visited by setting distance as 1
        
        int path_length = 1;
        
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                auto [row, col] = q.front();
                q.pop();
                
                // Check if we have reached the bottom-right cell
                if (row == n - 1 && col == n - 1) {
                    return path_length;
                }
                
                // Explore all 8 directions
                for (auto [dr, dc] : directions) {
                    int newRow = row + dr;
                    int newCol = col + dc;
                    
                    // Check if the new cell is within bounds and unvisited
                    if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < n && grid[newRow][newCol] == 0) {
                        q.push({newRow, newCol});
                        grid[newRow][newCol] = 1;  // Mark as visited
                    }
                }
            }
            path_length++;  // Increment path length after each BFS level
        }
        
        return -1;  // No path found
    }
};