class Solution {
public:
     int longestOnes(vector<int>& nums, int k) {
        int left = 0; // left pointer
        int zeroCount = 0; // count of zeroes in the current window
        int maxLength = 0; // maximum length of consecutive 1's

        for (int right = 0; right < nums.size(); right++) {
            // If we encounter a zero, increase the zero count
            if (nums[right] == 0) {
                zeroCount++;
            }

            // If zeroCount exceeds k, shrink the window from the left
            while (zeroCount > k) {
                if (nums[left] == 0) {
                    zeroCount--; // decrease the count of zeroes
                }
                left++; // move the left pointer to the right
            }

            // Calculate the maximum length of the window that contains at most k zeroes
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength; // return the result
    }
};