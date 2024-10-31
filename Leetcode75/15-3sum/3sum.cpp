#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        // Sort the input to enable two-pointer approach
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> result;

        for (int i = 0; i < nums.size() - 2; ++i) {
            // Skip duplicate values for the first element of the triplet
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum == 0) {
                    result.push_back({nums[i], nums[left], nums[right]});
                    
                    // Move to the next unique element for the left pointer
                    while (left < right && nums[left] == nums[left + 1]) ++left;
                    // Move to the next unique element for the right pointer
                    while (left < right && nums[right] == nums[right - 1]) --right;

                    ++left;
                    --right;
                } else if (sum < 0) {
                    ++left;  // Increase sum by moving left pointer to the right
                } else {
                    --right; // Decrease sum by moving right pointer to the left
                }
            }
        }
        
        return result;
    }
};
