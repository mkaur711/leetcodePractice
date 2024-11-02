#include <vector>
#include <limits>

class Solution {
public:
    int findPeakElement(std::vector<int>& nums) {
        int left = 0;
        int right = nums.size();

        while (left < right) {
            int mid = (left + right) / 2;
            int mid_val = nums[mid];
            int to_left = (mid > 0) ? nums[mid - 1] : std::numeric_limits<int>::min();
            int to_right = (mid < nums.size() - 1) ? nums[mid + 1] : std::numeric_limits<int>::min();

            if (to_left < mid_val && mid_val > to_right) {
                return mid;
            } else if (to_left < mid_val && mid_val < to_right) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};

