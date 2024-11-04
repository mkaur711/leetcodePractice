class Solution {
public:
    bool isNumber(string s) {
        // Remove leading and trailing whitespace
        s.erase(0, s.find_first_not_of(" "));
        s.erase(s.find_last_not_of(" ") + 1);

        if (s.empty()) {
            return false;  // Empty string after stripping whitespace is invalid
        }

        // Flags to track the parts of the number
        bool numSeen = false;
        bool dotSeen = false;
        bool expSeen = false;
        bool numAfterExp = true;

        for (size_t i = 0; i < s.size(); ++i) {
            char c = s[i];

            if (isdigit(c)) {
                numSeen = true;
                numAfterExp = true;  // Valid digit after exponent
            } else if (c == '.') {
                // A dot is allowed only if we haven't seen an exponent or another dot
                if (dotSeen || expSeen) {
                    return false;
                }
                dotSeen = true;
            } else if (c == 'e' || c == 'E') {
                // An exponent is allowed only if we have seen a number and haven't seen another exponent
                if (expSeen || !numSeen) {
                    return false;
                }
                expSeen = true;
                numAfterExp = false;  // Need digits after exponent
            } else if (c == '+' || c == '-') {
                // A sign is allowed only at the start or immediately after an exponent
                if (i > 0 && s[i - 1] != 'e' && s[i - 1] != 'E') {
                    return false;
                }
            } else {
                // Any other character is invalid
                return false;
            }
        }

        // Final check: must have seen at least one number and if an exponent was present, it must have been followed by digits
        return numSeen && numAfterExp;

    }
};