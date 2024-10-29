class Solution {
public:
    void nextPermutation(vector<int>& nums) {
         int n = nums.size();
    int pivot = n - 2;
    
    // Step 1: Find the pivot (first decreasing element from the end)
    while (pivot >= 0 && nums[pivot] >= nums[pivot + 1]) {
        --pivot;
    }
    
    if (pivot >= 0) {
        // Step 2: Find the element to swap with the pivot
        int swapIndex = n - 1;
        while (nums[swapIndex] <= nums[pivot]) {
            --swapIndex;
        }
        swap(nums[pivot], nums[swapIndex]);
    }
    
    // Step 3: Reverse the suffix starting from pivot + 1
    reverse(nums.begin() + pivot + 1, nums.end());
    }
};