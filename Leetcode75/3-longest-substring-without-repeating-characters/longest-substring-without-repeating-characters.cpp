class Solution {
public:
    int lengthOfLongestSubstring(const std::string& s) {
    std::unordered_map<char, int> last_seen; // Maps each character to its last seen index
    int max_length = 0; // Stores the max length of unique-character substring found
    int left = 0; // Left pointer of the sliding window

    for (int right = 0; right < s.size(); ++right) {
        char current_char = s[right];

        // If current character is already in the map and within the current window
        if (last_seen.count(current_char) && last_seen[current_char] >= left) {
            left = last_seen[current_char] + 1; // Move left pointer to skip the repeated character
        }

        last_seen[current_char] = right; // Update or add current character’s index
        max_length = std::max(max_length, right - left + 1); // Update max length if we find a longer substring
    }

    return max_length;
}
};