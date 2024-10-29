class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Step 1: Count frequencies of each element
        unordered_map<int, int> freqMap;
        for (int num : nums) {
            freqMap[num]++;
        }

        // Step 2: Use a min-heap to keep the top k elements
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        
        for (auto& [num, freq] : freqMap) {
            minHeap.push({freq, num});
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        // Step 3: Extract elements from the heap
        vector<int> result;
        while (!minHeap.empty()) {
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }
        
        return result;
    }
};