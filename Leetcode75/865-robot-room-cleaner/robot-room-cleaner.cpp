/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */

#include <unordered_set>
#include <vector>
#include <string>
using namespace std;

// Define directions: up, right, down, left
const vector<pair<int, int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

class Solution {
public:
    void cleanRoom(Robot& robot) {
        unordered_set<string> visited;
        dfs(robot, 0, 0, 0, visited); // Start at (0, 0) facing "up"
    }

private:
    void dfs(Robot& robot, int x, int y, int direction, unordered_set<string>& visited) {
        // Mark current cell as cleaned and visited
        robot.clean();
        visited.insert(cellKey(x, y));

        // Explore all 4 directions
        for (int i = 0; i < 4; i++) {
            int newDir = (direction + i) % 4;
            int newX = x + directions[newDir].first;
            int newY = y + directions[newDir].second;

            if (visited.find(cellKey(newX, newY)) == visited.end() && robot.move()) {
                dfs(robot, newX, newY, newDir, visited);

                // Backtrack to previous cell
                robot.turnLeft();
                robot.turnLeft();
                robot.move();
                robot.turnLeft();
                robot.turnLeft();
            }

            // Turn robot to the next direction
            robot.turnRight();
        }
    }

    // Helper function to encode cell coordinates as a string
    string cellKey(int x, int y) {
        return to_string(x) + "," + to_string(y);
    }
};
