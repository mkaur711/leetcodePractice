class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0; // Initialize candidate
    int count = 0; // Initialize count to track candidate votes

    // Loop to determine the majority element candidate
    for (int num : nums) {
        if (count == 0) { 
            candidate = num; // Set candidate to current number if count is zero
        }
        count += (num == candidate) ? 1 : -1; // Increment count if num == candidate; otherwise, decrement
    }
    
    return candidate; // The majority element is the candidate
    }
};