class Solution {
public:
    int minProcessingTime(vector<int>& p, vector<int>& t) {
       sort(t.begin(), t.end()); // Step 1: Sort task times in ascending order
    sort(p.rbegin(), p.rend()); // Step 2: Sort processor times in descending order

    int maxi = 0; // Initialize the maximum processing time
    int i = 0, j = 0; // Initialize indices for tasks and processors

    // Step 3: Assign tasks to processors
    while (i < t.size()) {
        int temp = t.size() / p.size(); // Number of tasks per processor (since each processor has 4 cores)
        
        // For each processor, assign the next set of tasks and update the maximum processing time
        while (temp--) {
            maxi = max(maxi, (p[j] + t[i++])); // Update maxi with the maximum time it takes to complete a task on the current processor core
        }
        
        j++; // Move to the next processor
    }

    return maxi; // Step 4: Return the minimum processing time needed to complete all tasks
}};