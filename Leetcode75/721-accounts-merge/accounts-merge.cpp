class Solution {
public:
    // DFS function to explore connected components
void dfs(const string& email, unordered_map<string, vector<string>>& graph, set<string>& component, unordered_map<string, bool>& visited) {
    visited[email] = true;
    component.insert(email);
    for (const string& neighbor : graph[email]) {
        if (!visited[neighbor]) {
            dfs(neighbor, graph, component, visited);
        }
    }
}

vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    unordered_map<string, string> emailToName;  // Map each email to the corresponding name
    unordered_map<string, vector<string>> graph;  // Graph of emails connected by shared accounts
    unordered_map<string, bool> visited;  // To track visited emails
    
    // Build the graph and emailToName map
    for (auto& account : accounts) {
        const string& name = account[0];
        for (int i = 1; i < account.size(); ++i) {
            const string& email = account[i];
            emailToName[email] = name;  // Record the name associated with each email
            if (i > 1) {  // Add an edge between consecutive emails in the account
                graph[account[i]].push_back(account[i-1]);
                graph[account[i-1]].push_back(account[i]);
            }
        }
    }
    
    vector<vector<string>> result;
    
    // Perform DFS on each email that hasn't been visited yet
    for (auto& entry : emailToName) {
        if (!visited[entry.first]) {
            set<string> component;  // Set to store emails of the same person
            dfs(entry.first, graph, component, visited);
            vector<string> mergedAccount = {emailToName[entry.first]};  // Add name to result
            mergedAccount.insert(mergedAccount.end(), component.begin(), component.end());  // Add emails
            sort(mergedAccount.begin() + 1, mergedAccount.end());  // Sort emails lexicographically
            result.push_back(mergedAccount);
        }
    }
    
    return result;
}
};