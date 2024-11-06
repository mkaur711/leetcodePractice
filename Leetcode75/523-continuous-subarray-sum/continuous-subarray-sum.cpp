#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> remainderMap;
        remainderMap[0] = -1;  // Initialize with remainder 0 at index -1 to handle edge cases
        int cumulativeSum = 0;

        for (int i = 0; i < nums.size(); i++) {
            cumulativeSum += nums[i];
            int remainder = cumulativeSum % k;

            // Handling negative remainders (optional, depending on language specifics)
            if (remainder < 0) remainder += k;

            if (remainderMap.find(remainder) != remainderMap.end()) {
                if (i - remainderMap[remainder] > 1) {
                    return true;  // Found a subarray of length >= 2 with the required property
                }
            } else {
                remainderMap[remainder] = i;  // Store the first occurrence of this remainder
            }
        }

        return false;  // No valid subarray found
    }
};
