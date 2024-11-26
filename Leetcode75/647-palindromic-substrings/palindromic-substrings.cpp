class Solution {
public:
    // Function to count palindromic substrings using the expand around center approach
int countSubstrings(string s) {
    int n = s.length();
    int count = 0;
    
    // Helper function to expand around a center and count palindromes
    auto expandAroundCenter = [&](int left, int right) {
        int localCount = 0;
        while (left >= 0 && right < n && s[left] == s[right]) {
            localCount++; // Found a palindrome
            left--;       // Expand to the left
            right++;      // Expand to the right
        }
        return localCount;
    };
    
    // Iterate through each possible center
    for (int i = 0; i < n; ++i) {
        // Odd-length palindromes (single character center)
        count += expandAroundCenter(i, i);
        
        // Even-length palindromes (two character center)
        count += expandAroundCenter(i, i + 1);
    }
    
    return count;
}
};