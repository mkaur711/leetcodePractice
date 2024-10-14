class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
    int i = 0, j = 0; // i for word, j for abbr

    while (i < word.length() && j < abbr.length()) {
        if (isalpha(abbr[j])) {
            // If the character in abbreviation is a letter, it should match the word's character
            if (word[i] != abbr[j]) {
                return false;
            }
            i++;
            j++;
        } else if (isdigit(abbr[j])) {
            // If it's a digit, calculate the number of characters to skip
            if (abbr[j] == '0') {
                return false; // leading zeros are not allowed
            }
            int num = 0;
            while (j < abbr.length() && isdigit(abbr[j])) {
                num = num * 10 + (abbr[j] - '0');
                j++;
            }
            i += num; // Skip the characters in word
        }
    }

    // Check if both word and abbreviation have been completely traversed
    return i == word.length() && j == abbr.length();
    }
};