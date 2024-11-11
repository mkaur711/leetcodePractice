class Solution {
public:
    int missingNumber(vector<int>& nums) {
         // Calculate the expected sum of numbers from 0 to n
        int n = nums.size();
        int expectedSum = n * (n + 1) / 2;
        
        // Calculate the actual sum of elements in nums
        int actualSum = 0;
        for (int num : nums) {
            actualSum += num;
        }
        
        // The missing number is the difference between expected and actual sums
        return expectedSum - actualSum;
    }
};