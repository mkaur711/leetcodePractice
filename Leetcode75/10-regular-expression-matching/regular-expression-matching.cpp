class Solution {
public:
    public:
    bool isMatch(string s, string p) {
        return helper(s, p, 0, 0);
    }

private:
    // Helper function to recursively match strings
    bool helper(const string& s, const string& p, int i, int j) {
        // If we've reached the end of the pattern
        if (j == p.size()) return i == s.size();

        // Check if the current characters match
        bool firstMatch = (i < s.size() && (s[i] == p[j] || p[j] == '.'));

        // Handle '*' in the pattern
        if (j + 1 < p.size() && p[j + 1] == '*') {
            // Either skip the '*' or consume one character in s
            return helper(s, p, i, j + 2) || (firstMatch && helper(s, p, i + 1, j));
        } else {
            // Match current characters and move to the next
            return firstMatch && helper(s, p, i + 1, j + 1);
        }
    }
};
