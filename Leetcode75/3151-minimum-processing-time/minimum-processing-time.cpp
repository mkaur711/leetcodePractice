class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
    // Sort processor times in ascending order
    sort(processorTime.begin(), processorTime.end());
    
    // Initialize a max heap to keep the tasks with the longest processing times on top
    priority_queue<int> pq;
    for (auto& x : tasks) {
        pq.push(x); // Push each task duration into the priority queue
    }

    int n = processorTime.size(); // Number of processors
    int mx = 0; // Initialize variable to track the maximum processing time

    // Distribute tasks to each processor
    for (int i = 0; i < n; i++) {
        int sz = 0; // Tracks how many tasks have been assigned to the current processor
        
        // Each processor should handle 4 tasks
        while (!pq.empty() && sz < 4) {
            // Calculate time by adding current processor's time and the longest task available
            mx = max(mx, processorTime[i] + pq.top());
            pq.pop(); // Remove the task from the queue
            sz++; // Increment the task count for the current processor
        }
    }
    
    return mx; // Return the minimum time required to complete all tasks
}
};