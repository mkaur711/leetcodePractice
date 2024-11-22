class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        // Calculate the sum of the first window
        double currentSum = 0;
        for (int i = 0; i < k; ++i) {
            currentSum += nums[i];
        }

        // Initialize the maximum sum as the current sum
        double maxSum = currentSum;

        // Slide the window over the array
        for (int i = k; i < nums.size(); ++i) {
            // Add the next element and remove the first element of the current window
            currentSum += nums[i] - nums[i - k];
            // Update the maximum sum if needed
            maxSum = std::max(maxSum, currentSum);
        }

        // Return the maximum average
        return maxSum / k;
    }
};