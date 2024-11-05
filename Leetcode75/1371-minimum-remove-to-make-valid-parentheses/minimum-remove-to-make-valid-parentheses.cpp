class Solution {
public:
    string minRemoveToMakeValid(string s) {
     int cnt = 0; // To count unmatched '('
        vector<char> res; // Temporary storage for result

        // First pass: Append valid parentheses and characters to res
        for (char c : s) {
            if (c == '(') {
                cnt++; // Increment for every '('
                res.push_back(c); // Add '(' to result
            } else if (c == ')') {
                if (cnt > 0) {
                    res.push_back(c); // Add ')' to result if there's a matching '('
                    cnt--; // Decrement unmatched '(' count
                }
            } else {
                res.push_back(c); // Add all other characters
            }
        }

        // Prepare the final string, filtering unmatched '(' from the end
        string filtered_string;
        // Iterate the result in reverse to filter unmatched '('
        for (int i = res.size() - 1; i >= 0; i--) {
            if (res[i] == '(' && cnt > 0) {
                cnt--; // Skip unmatched '('
            } else {
                filtered_string.push_back(res[i]); // Keep valid characters
            }
        }

        // Reverse the filtered string
        reverse(filtered_string.begin(), filtered_string.end());

        return filtered_string; // Return the valid string
    }

};