class Solution {
public:
    // Helper function for recursion with memoization
    vector<string> wordBreakHelper(const string& s, unordered_set<string>& wordDict, unordered_map<string, vector<string>>& memo) {
        if (memo.find(s) != memo.end()) return memo[s];  // Return cached result
        if (s.empty()) return {""};  // Base case: empty string
        
        vector<string> sentences;
        // Iterate through possible prefixes
        for (int i = 1; i <= s.size(); ++i) {
            string prefix = s.substr(0, i);
            if (wordDict.find(prefix) != wordDict.end()) {  // Check if prefix is in dictionary
                vector<string> suffixSentences = wordBreakHelper(s.substr(i), wordDict, memo);
                for (const string& sentence : suffixSentences) {
                    sentences.push_back(prefix + (sentence.empty() ? "" : " " + sentence));
                }
            }
        }
        memo[s] = sentences;  // Cache result
        return sentences;
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        unordered_map<string, vector<string>> memo;  // Memoization map
        return wordBreakHelper(s, wordSet, memo);
    }
};