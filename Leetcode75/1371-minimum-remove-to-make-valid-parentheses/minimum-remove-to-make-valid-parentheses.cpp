class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int openCount = 0; // Count of unmatched opening brackets

        // First pass: Remove invalid closing brackets ')'
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                openCount++; // Increment count for '('
            } else if (s[i] == ')') {
                if (openCount > 0) {
                    openCount--; // Match with a previous '('
                } else {
                    s[i] = '*'; // Mark invalid ')'
                }
            }
        }

        int closeCount = 0; // Count of unmatched closing brackets

        // Second pass: Remove extra opening brackets '('
        for (int i = s.size() - 1; i >= 0; --i) {
            if (s[i] == ')') {
                closeCount++; // Increment count for ')'
            } else if (s[i] == '(') {
                if (closeCount > 0) {
                    closeCount--; // Match with a previous ')'
                } else {
                    s[i] = '*'; // Mark excess '('
                }
            }
        }

        // Build the final result by skipping marked characters
        string result;
        for (char c : s) {
            if (c != '*') {
                result += c; // Add only valid characters
            }
        }

        return result;
    }
};
