class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Step 1: Count frequencies of each element
        unordered_map<int, int> freqMap;
        for (int num : nums) {
            freqMap[num]++;
        }

        // Step 2: Create buckets to store numbers with the same frequency
        int n = nums.size();
        vector<vector<int>> buckets(n + 1);
        for (auto& [num, freq] : freqMap) {
            buckets[freq].push_back(num);
        }

        // Step 3: Collect the top k frequent elements
        vector<int> result;
        for (int i = n; i >= 0 && result.size() < k; --i) {
            for (int num : buckets[i]) {
                result.push_back(num);
                if (result.size() == k) {
                    return result;
                }
            }
        }

        return result;
    }
};