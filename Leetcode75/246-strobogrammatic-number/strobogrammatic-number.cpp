class Solution {
public:
    bool isStrobogrammatic(string num) {
        // Map for strobogrammatic digit pairs
        std::unordered_map<char, char> strobogrammaticMap = {
            {'0', '0'},
            {'1', '1'},
            {'6', '9'},
            {'8', '8'},
            {'9', '6'}
        };
        
        int left = 0;
        int right = num.size() - 1;
        
        while (left <= right) {
            char leftChar = num[left];
            char rightChar = num[right];
            
            // Check if the left character is valid and if it matches the expected right character
            if (strobogrammaticMap.find(leftChar) == strobogrammaticMap.end() || 
                strobogrammaticMap[leftChar] != rightChar) {
                return false; // Not strobogrammatic
            }
            
            left++;
            right--;
        }
        
        return true; // It is strobogrammatic
    }
};