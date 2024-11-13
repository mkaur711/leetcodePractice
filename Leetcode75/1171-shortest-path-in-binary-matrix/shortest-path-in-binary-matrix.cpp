class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
    // Directions for 8-directional movement (up, down, left, right, diagonals)
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
    
    // If the start or end is blocked, return -1
    if (grid[0][0] == 1 || grid[n-1][n-1] == 1) {
        return -1;
    }
    
    queue<pair<int, int>> q;
    q.push({0, 0});  // Starting position
    grid[0][0] = 1;  // Mark as visited
    
    int pathLength = 1;  // Starting at the first cell
    
    while (!q.empty()) {
        int size = q.size();
        
        // Process all nodes at the current level
        for (int i = 0; i < size; ++i) {
            auto [x, y] = q.front();
            q.pop();
            
            // If we reach the bottom-right corner, return the path length
            if (x == n-1 && y == n-1) {
                return pathLength;
            }
            
            // Explore 8 directions
            for (auto& dir : directions) {
                int newX = x + dir.first;
                int newY = y + dir.second;
                
                // Check if the new position is valid and not blocked
                if (newX >= 0 && newX < n && newY >= 0 && newY < n && grid[newX][newY] == 0) {
                    q.push({newX, newY});
                    grid[newX][newY] = 1;  // Mark as visited
                }
            }
        }
        
        // Increase path length after processing the current level
        pathLength++;
    }
    
    return -1;  // Return -1 if there's no valid path
    }
};