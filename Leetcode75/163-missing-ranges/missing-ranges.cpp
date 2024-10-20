class Solution {
public:
    vector<vector<int>> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<vector<int>> missingRanges;
        long long start = lower; // Use long long to avoid overflow

        // Iterate through the sorted unique integer array
        for (int num : nums) {
            if (num > start) {
                // If there are missing numbers
                if (num - start == 1) {
                    // Only one missing number
                    missingRanges.push_back({static_cast<int>(start), static_cast<int>(start)});
                } else {
                    // More than one missing number, create a range
                    missingRanges.push_back({static_cast<int>(start), static_cast<int>(num - 1)});
                }
            }
            // Update start to the next number after the current
            start = static_cast<long long>(num) + 1;
        }

        // Check if there are missing numbers after the last element
        if (start <= upper) {
            if (start == upper) {
                missingRanges.push_back({static_cast<int>(start), static_cast<int>(start)});
            } else {
                missingRanges.push_back({static_cast<int>(start), static_cast<int>(upper)});
            }
        }

        return missingRanges;
    }
};