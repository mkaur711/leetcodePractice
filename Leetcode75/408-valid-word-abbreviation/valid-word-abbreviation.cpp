class Solution {
public:
    bool validWordAbbreviation(string word,string abbr){
          int wordIndex = 0, abbrIndex = 0;
    
    while (abbrIndex < abbr.size() && wordIndex < word.size()) {
        // If the current character in abbr is a letter
        if (isalpha(abbr[abbrIndex])) {
            if (word[wordIndex] != abbr[abbrIndex]) {
                return false; // Mismatch
            }
            wordIndex++;
            abbrIndex++;
        } 
        // If the current character in abbr is a digit
        else if (isdigit(abbr[abbrIndex])) {
            if (abbr[abbrIndex] == '0') {
                return false; // Leading zeros are not allowed
            }
            int num = 0;
            // Parse the entire number in abbr
            while (abbrIndex < abbr.size() && isdigit(abbr[abbrIndex])) {
                num = num * 10 + (abbr[abbrIndex] - '0');
                abbrIndex++;
            }
            wordIndex += num; // Skip characters in word
        }
    }
    // Check if both pointers have reached the end
    return wordIndex == word.size() && abbrIndex == abbr.size();
    }
};