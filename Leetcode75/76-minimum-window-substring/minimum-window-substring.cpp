class Solution {
public:
    string minWindow(string s, string t) {
        // Step 1: Count the characters in t
    std::unordered_map<char, int> t_count;
    for (char c : t) {
        t_count[c]++;
    }
    
    int required = t_count.size();  // Number of unique characters in t
    int l = 0, r = 0;                // Left and right pointers
    int formed = 0;                  // Count of unique characters in the current window
    std::unordered_map<char, int> window_counts;  // Character counts in the current window
    
    // Step 2: Initialize variables to store the result
    int min_len = INT_MAX;           // Initialize min length as maximum integer
    int min_left = 0, min_right = 0; // Start and end indices of the minimum window

    // Step 3: Expand the window
    while (r < s.length()) {
        char char_right = s[r];  // Current character at the right pointer
        window_counts[char_right]++;  // Add current char to the window
        
        // Check if the current character's count matches the required count in t
        if (t_count.find(char_right) != t_count.end() && window_counts[char_right] == t_count[char_right]) {
            formed++;  // A unique character requirement is satisfied
        }

        // Step 4: Contract the window if all characters are formed
        while (l <= r && formed == required) {
            char char_left = s[l];  // Character at the left pointer

            // Update minimum window size
            if (r - l + 1 < min_len) {
                min_len = r - l + 1;
                min_left = l;
                min_right = r;
            }

            // Remove the character from the window
            window_counts[char_left]--;
            if (t_count.find(char_left) != t_count.end() && window_counts[char_left] < t_count[char_left]) {
                formed--;  // We no longer have enough of this character
            }

            l++;  // Move the left pointer to the right
        }

        r++;  // Move the right pointer to the right
    }

    // Step 5: Return the minimum window substring
    return min_len == INT_MAX ? "" : s.substr(min_left, min_len);
    }
};