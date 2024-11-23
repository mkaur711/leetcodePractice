class NumArray {
    private:
    std::vector<int> prefixSum; // To store prefix sums

public:
    
    // Constructor: preprocess prefix sums
    NumArray(std::vector<int>& nums) {
        int n = nums.size();
        prefixSum.resize(n + 1, 0); // Initialize with size n+1, all 0
        for (int i = 0; i < n; ++i) {
            prefixSum[i + 1] = prefixSum[i] + nums[i]; // Build prefix sum
        }
    }

    // Query: calculate range sum
    int sumRange(int left, int right) {
        return prefixSum[right + 1] - prefixSum[left]; // Range sum in O(1)
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */