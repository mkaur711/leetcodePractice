class Solution {
public:
    bool rotateString(string s, string goal) {
        // Check if lengths are different, return false
        if (s.length() != goal.length()) return false;
        
        // Concatenate s with itself
        string concatenated = s + s;
        
        // Check if goal is a substring of concatenated
        return concatenated.find(goal) != string::npos;
    }
};