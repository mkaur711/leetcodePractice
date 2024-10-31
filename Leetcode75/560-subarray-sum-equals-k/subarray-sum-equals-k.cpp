class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixSumCount;
        prefixSumCount[0] = 1; // Initialize with sum 0 for cases where currSum == k
        int currSum = 0;
        int count = 0;
        
        for (int num : nums) {
            currSum += num;
            
            // Check if there exists a subarray that sums to k
            if (prefixSumCount.find(currSum - k) != prefixSumCount.end()) {
                count += prefixSumCount[currSum - k];
            }
            
            // Update the map with the current prefix sum
            prefixSumCount[currSum]++;
        }
        
        return count;
    }
};