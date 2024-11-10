class Solution {
public:
    string intToRoman(int num) {
        // Ordered lists of values and their corresponding Roman symbols
    std::vector<int> values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    std::vector<std::string> symbols = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    
    std::string result = ""; // This will store our final Roman numeral representation
    
    // Iterate over each value-symbol pair
    for (int i = 0; i < values.size(); ++i) {
        // Append the symbol as many times as it fits in the remaining number
        while (num >= values[i]) {
            result += symbols[i];
            num -= values[i]; // Subtract the corresponding value from num
        }
    }
    
    return result; // Return the complete Roman numeral string
    }
};