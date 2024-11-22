class Solution {
public:
    // Function to check if words are sorted in alien order
bool isAlienSorted(vector<string>& words, string order) {
    // Map each character in the alien order to its index
    unordered_map<char, int> orderMap;
    for (int i = 0; i < order.size(); ++i) {
        orderMap[order[i]] = i;
    }

    // Compare adjacent words
    for (int i = 0; i < words.size() - 1; ++i) {
        string word1 = words[i];
        string word2 = words[i + 1];
        
        // Compare characters of the two words
        for (int j = 0; j < min(word1.size(), word2.size()); ++j) {
            char char1 = word1[j];
            char char2 = word2[j];

            // If characters are different, check their order
            if (char1 != char2) {
                if (orderMap[char1] > orderMap[char2]) {
                    return false; // Wrong order
                }
                break; // Stop comparing once we find the mismatch
            }
        }

        // Handle prefix case where word1 is longer than word2
        if (word1.size() > word2.size() && word1.substr(0, word2.size()) == word2) {
            return false;
        }
    }

    return true; // All words are in correct order
}
};