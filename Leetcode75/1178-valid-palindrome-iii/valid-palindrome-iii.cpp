class Solution {
public:
    bool isValidPalindrome(string s, int k) {
        // Calculate the length of the string
        int n = s.size();

        // dp[i][j] will store the minimum number of deletions required to make the substring s[i...j] a palindrome
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Fill the DP table
        for (int len = 2; len <= n; ++len) {  // len is the length of the substring
            for (int i = 0; i < n - len + 1; ++i) {
                int j = i + len - 1;  // j is the end of the substring

                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1];  // No deletion required if characters match
                } else {
                    dp[i][j] = 1 + min(dp[i + 1][j], dp[i][j - 1]);  // Deletion either from the left or the right
                }
            }
        }

        // The minimum number of deletions required to make the entire string a palindrome
        return dp[0][n - 1] <= k;
    }
};