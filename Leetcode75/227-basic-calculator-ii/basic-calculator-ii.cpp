
class Solution {
public:
    int calculate(string s) {
        int result = 0;  // Final result
        int current = 0; // Current intermediate value
        int num = 0;     // Current number being processed
        char lastOperator = '+'; // Tracks the last operator

        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];

            // If current character is a digit, build the number
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            }

            // If current character is an operator or the end of the string
            if ((!isdigit(c) && c != ' ') || i == s.size() - 1) {
                if (lastOperator == '+') {
                    result += current; // Add the last evaluated term to the result
                    current = num; // Update current term
                } else if (lastOperator == '-') {
                    result += current; // Add the last evaluated term to the result
                    current = -num; // Update current term as negative
                } else if (lastOperator == '*') {
                    current *= num; // Update current term with multiplication
                } else if (lastOperator == '/') {
                    current /= num; // Update current term with division
                }

                // Update the last operator and reset the number
                lastOperator = c;
                num = 0;
            }
        }

        // Add the final term
        result += current;
        return result;
    }
};

