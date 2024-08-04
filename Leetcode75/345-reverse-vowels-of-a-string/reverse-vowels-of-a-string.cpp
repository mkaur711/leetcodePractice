// class Solution {
// public:
//     bool isVowel(char s){
//         s=tolower(s);
//         if(s=='a' ||s=='e'||s=='i'||s=='o'||s=='u'){
//             return true;
//         }
//         else
//         return false;
//     }
//     string reverseVowels(string s) {
//         int l=0;
//         int r= s.length()-1;
//         while(l<r){
//             if(!isVowel(s[r])){
//                 r--;
//             }
//             if(!isVowel(s[l])){
//                 l++;
//             }
//             if(isVowel(s[l]) && isVowel(s[r])){
//                 swap(s[l],s[r]);
//                 l++;
//                 r--;
//             }
            
//         }
//         return s;
//     }
// };

class Solution {
public:
    bool isVowel(char s) {
        s = tolower(s);  // Convert character to lowercase to handle both cases
        return (s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u');
    }

    string reverseVowels(string s) {
        int l = 0;
        int r = s.length() - 1;  // Correct length

        while (l < r) {
            // Move left pointer to the next vowel
            while (l < r && !isVowel(s[l])) {
                l++;
            }
            // Move right pointer to the previous vowel
            while (l < r && !isVowel(s[r])) {
                r--;
            }
            // Swap vowels
            if (l < r) {
                swap(s[l], s[r]);
                l++;
                r--;
            }
        }

        return s;
    }
};
