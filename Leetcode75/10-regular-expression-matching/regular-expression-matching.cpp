class Solution {
public:
    bool isMatch(string text, string pattern) {
        // Create a 2D dp table to store results of subproblems.
        // dp[i][j] will be true if text[i:] matches pattern[j:].
        vector<vector<bool>> dp(text.size() + 1, vector<bool>(pattern.size() + 1, false));
        
        // An empty pattern matches an empty text.
        dp[text.size()][pattern.size()] = true;

        // Fill the dp table from bottom-right to top-left.
        for (int i = text.size(); i >= 0; --i) { // Loop over text from end to start
            for (int j = pattern.size() - 1; j >= 0; --j) { // Loop over pattern from end to start
                // Check if the current characters of text and pattern match
                bool first_match = (i < text.size() && 
                                    (pattern[j] == text[i] || pattern[j] == '.'));

                // If the next character in pattern is '*', handle it as zero or more of the preceding character
                if (j + 1 < pattern.size() && pattern[j + 1] == '*') {
                    // Two options: 
                    // 1. We ignore '*' and its preceding character: dp[i][j + 2]
                    // 2. If there's a match, use '*' to match one or more of the preceding character: first_match && dp[i + 1][j]
                    dp[i][j] = dp[i][j + 2] || (first_match && dp[i + 1][j]);
                } else {
                    // No '*', so we proceed to the next characters in both text and pattern
                    dp[i][j] = first_match && dp[i + 1][j + 1];
                }
            }
        }
        
        // The result of matching the full text with the full pattern is stored in dp[0][0].
        return dp[0][0];
    }
};
