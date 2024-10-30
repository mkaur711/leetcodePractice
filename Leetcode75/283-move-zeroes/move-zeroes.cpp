class Solution {
public:
    void moveZeroes(vector<int>& nums) {
    int lastNonZeroIndex = 0;

    // Move all non-zero elements to the beginning
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != 0) {
            // Swap only if i is different from lastNonZeroIndex
            if (i != lastNonZeroIndex) {
                swap(nums[i], nums[lastNonZeroIndex]);
            }
            lastNonZeroIndex++;
        }
    }
    }
};