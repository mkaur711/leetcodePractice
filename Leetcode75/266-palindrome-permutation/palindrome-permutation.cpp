class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> charCount;  // HashMap to store character frequencies
        
        // Iterate through the string and count the occurrences of each character
        for (char c : s) {
            charCount[c]++;  // Increment the count for each character
        }

        int oddCount = 0;  // Variable to track the number of characters with odd frequencies
        // Check how many characters have an odd frequency
        for (auto& pair : charCount) {
            if (pair.second % 2 != 0) {
                oddCount++;  // If the count is odd, increment oddCount
                if (oddCount > 1) return false;  // More than one odd count means it's not a palindrome permutation
            }
        }

        return true;  // If we have at most one odd count, return true
    }
};