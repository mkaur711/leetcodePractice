class Solution {
public:
    int calculate(string s) {
        int result = 0;
        int lastNumber = 0;
        int currentNumber = 0;
        char lastOperator = '+'; // Initialize to '+' so the first number is added

        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];

            // If the character is a digit, build the current number
            if (isdigit(c)) {
                currentNumber = currentNumber * 10 + (c - '0');
            }

            // If we reach an operator or the end of the string, process the last operator
            if ((!isdigit(c) && !isspace(c)) || i == s.size() - 1) {
                if (lastOperator == '+') {
                    result += lastNumber; // Add last calculated number to result
                    lastNumber = currentNumber; // Update lastNumber to current number
                } else if (lastOperator == '-') {
                    result += lastNumber;
                    lastNumber = -currentNumber;
                } else if (lastOperator == '*') {
                    lastNumber *= currentNumber; // Multiply last number by current number
                } else if (lastOperator == '/') {
                    lastNumber /= currentNumber; // Divide last number by current number
                }

                // Update last operator and reset current number
                lastOperator = c;
                currentNumber = 0;
            }
        }

        // Add the last processed number to the result
        result += lastNumber;
        return result;
    }
};