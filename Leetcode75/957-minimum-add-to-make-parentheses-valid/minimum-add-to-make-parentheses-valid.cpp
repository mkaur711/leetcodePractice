class Solution {
public:
    int minAddToMakeValid(string s) {
        int leftCount = 0;   // Tracks unmatched '('
    int rightCount = 0;  // Tracks unmatched ')'
    int toAdd = 0;       // Total parentheses needed to add to make the string valid
    
    for (char c : s) {
        if (c == '(') {
            leftCount++;
        } else if (c == ')') {
            if (leftCount > 0) {
                leftCount--; // Match ')' with '('
            } else {
                rightCount++; // Need an extra '('
            }
        }
    }
    
    toAdd = leftCount + rightCount;
    return toAdd;
    }
};