class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0; // Pointer for the next position of valid elements

        // Iterate through the array
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[k] = nums[i]; // Move valid element to the k-th position
                k++; // Increment the position pointer
            }
        }
        return k; // Return the number of valid elements
    }
};