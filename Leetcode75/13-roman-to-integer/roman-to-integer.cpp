class Solution {
public:
    int romanToInt(string s) {
        // Map to store the integer values of Roman numerals
    std::unordered_map<char, int> roman_map = {
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
    };

    int total = 0; // Result to store the integer value
    int last_value = 0; // To keep track of the last numeral's value for subtraction checks

    // Traverse from the end of the string to the beginning
    for (int i = s.size() - 1; i >= 0; --i) {
        int current_value = roman_map[s[i]]; // Get the integer value of the current Roman numeral

        // Check if we need to add or subtract the current value
        if (current_value < last_value) {
            total -= current_value; // Subtract if current is less than last (e.g., IV or IX)
        } else {
            total += current_value; // Add otherwise
        }
        
        last_value = current_value; // Update last_value to current for the next iteration
    }

    return total; // Return the converted integer value
    }
};