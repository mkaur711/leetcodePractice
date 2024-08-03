class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int l1 = word1.length();
        int l2 = word2.length();
        int l = 0, r = 0;
        string ans = "";
        while (l < l1 && r < l2) {
            ans += word1[l];
            ans += word2[r];
            l++;
            r++;
        }
        // Append remaining characters from word1 if any
        while (l < l1) {
            ans += word1[l];
            l++;
        }
        // Append remaining characters from word2 if any
        while (r < l2) {
            ans += word2[r];
            r++;
        }
        return ans;
    }
};
