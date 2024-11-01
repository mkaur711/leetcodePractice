#include <string>
#include <vector>
#include <unordered_set>

class Solution {
public:
    bool wordBreak(const std::string& s, const std::vector<std::string>& wordDict) {
        // Convert wordDict to a set for quick lookup
        std::unordered_set<std::string> wordSet(wordDict.begin(), wordDict.end());
        
        // dp array to keep track of segmentations
        std::vector<bool> dp(s.length() + 1, false);
        dp[0] = true;  // base case: empty string can be segmented
        
        for (int i = 1; i <= s.length(); i++) {
            for (int j = 0; j < i; j++) {
                // Check if s[j:i] is in wordDict and dp[j] is true
                if (dp[j] && wordSet.find(s.substr(j, i - j)) != wordSet.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        
        return dp[s.length()];
    }
};
