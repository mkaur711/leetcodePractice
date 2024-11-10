class Solution {
public:
    vector<int> orArray(vector<int>& nums) {
         std::vector<int> answer;
    
    // Loop through nums and perform OR operation on adjacent pairs
    for (int i = 0; i < nums.size() - 1; ++i) {
        // nums[i] | nums[i + 1] is stored in answer
        answer.push_back(nums[i] | nums[i + 1]);
    }
    
    return answer;
    }
};