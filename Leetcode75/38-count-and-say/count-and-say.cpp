class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1"; // Base case for n=1
    
    string current = "1"; // Starting point for sequence
    for (int i = 2; i <= n; ++i) { // Loop to build sequence up to nth term
        string next = ""; // String to store the next term in sequence
        int count = 1; // Initialize count of current character

        for (size_t j = 1; j < current.size(); ++j) { // Loop through current term
            if (current[j] == current[j - 1]) {
                count++; // Increment count if same character repeats
            } else {
                // Append count and character to next term
                next += to_string(count) + current[j - 1];
                count = 1; // Reset count for new character
            }
        }
        // Append final count and character for last group in current term
        next += to_string(count) + current.back();
        current = next; // Move to next term in sequence
    }
    return current; // Return the nth term
    }
};