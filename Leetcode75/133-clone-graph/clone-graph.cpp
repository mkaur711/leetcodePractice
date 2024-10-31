/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;

        // Use a map to track cloned nodes
        unordered_map<Node*, Node*> visited;

        // Start with the root node
        queue<Node*> q;
        q.push(node);
        visited[node] = new Node(node->val);

        while (!q.empty()) {
            Node* current = q.front();
            q.pop();

            // Iterate through each neighbor
            for (Node* neighbor : current->neighbors) {
                if (visited.find(neighbor) == visited.end()) {
                    // Clone the neighbor
                    visited[neighbor] = new Node(neighbor->val);
                    q.push(neighbor);
                }
                // Link the clone's neighbors
                visited[current]->neighbors.push_back(visited[neighbor]);
            }
        }
        return visited[node];
    }
};