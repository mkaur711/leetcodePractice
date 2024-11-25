
class Solution {
public:
    int calculate(string s) {
        stack<int> stk; // Stack to store intermediate results
        char lastOperator = '+'; // Tracks the last operator
        int num = 0; // Current number being processed

        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];

            // If current character is a digit, build the number
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            }

            // If current character is an operator or the end of the string
            if ((!isdigit(c) && c != ' ') || i == s.size() - 1) {
                if (lastOperator == '+') {
                    stk.push(num); // Add number to stack
                } else if (lastOperator == '-') {
                    stk.push(-num); // Subtract number
                } else if (lastOperator == '*') {
                    int top = stk.top();
                    stk.pop();
                    stk.push(top * num); // Multiply top of stack
                } else if (lastOperator == '/') {
                    int top = stk.top();
                    stk.pop();
                    stk.push(top / num); // Divide top of stack
                }

                // Update the last operator and reset the number
                lastOperator = c;
                num = 0;
            }
        }

        // Sum all numbers in the stack
        int result = 0;
        while (!stk.empty()) {
            result += stk.top();
            stk.pop();
        }

        return result;
    }
};
