#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Create an adjacency list for the graph
        unordered_map<int, vector<int>> graph;
        for (const auto& pre : prerequisites) {
            graph[pre[1]].push_back(pre[0]);
        }

        // Create a visited set to track the visiting status of each node
        unordered_set<int> visited;
        unordered_set<int> path; // To detect cycles

        // Perform DFS for each course
        for (int i = 0; i < numCourses; ++i) {
            if (!dfs(graph, i, visited, path)) {
                return false; // Cycle detected
            }
        }

        return true; // No cycles detected, can finish all courses
    }

private:
    bool dfs(unordered_map<int, vector<int>>& graph, int course, unordered_set<int>& visited, unordered_set<int>& path) {
        // If we have already visited this node, return true
        if (visited.count(course)) return true;
        // If we are visiting this node again in the current path, a cycle is detected
        if (path.count(course)) return false;

        // Mark the node as being visited in the current path
        path.insert(course);

        // Visit all the neighbors
        for (int neighbor : graph[course]) {
            if (!dfs(graph, neighbor, visited, path)) {
                return false;
            }
        }

        // Mark the node as completely visited
        path.erase(course);
        visited.insert(course);
        
        return true;
    }
};
