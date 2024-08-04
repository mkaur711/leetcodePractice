class Solution {
public:
    bool isVowel(char s){
        s=tolower(s);
        if(s=='a' ||s=='e'||s=='i'||s=='o'||s=='u'){
            return true;
        }
        else
        return false;
    }
    string reverseVowels(string s) {
        int l=0;
        int r= s.length()-1;
        while(l<r){
            if(!isVowel(s[r])){
                r--;
            }
            if(!isVowel(s[l])){
                l++;
            }
            if(isVowel(s[l]) && isVowel(s[r])){
                swap(s[l],s[r]);
                l++;
                r--;
            }
            
        }
        return s;
    }
};