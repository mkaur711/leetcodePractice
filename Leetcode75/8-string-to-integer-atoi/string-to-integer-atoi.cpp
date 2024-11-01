#include <string>
#include <climits>

class Solution {
public:
    int myAtoi(std::string s) {
        int i = 0, n = s.length();
        int sign = 1; // Default is positive
        long result = 0; // Store result as long to handle overflow during processing

        // Step 1: Ignore leading whitespaces
        while (i < n && s[i] == ' ') {
            i++;
        }

        // Step 2: Check for optional sign
        if (i < n && (s[i] == '-' || s[i] == '+')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // Step 3: Read in next sequence of digits
        while (i < n && isdigit(s[i])) {
            result = result * 10 + (s[i] - '0');
            
            // Step 4: Check for overflow
            if (sign * result > INT_MAX) {
                return INT_MAX;
            }
            if (sign * result < INT_MIN) {
                return INT_MIN;
            }
            i++;
        }

        // Return final result with the sign applied
        return sign * result;
    }
};
