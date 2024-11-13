class Solution {
public:
    bool validWordAbbreviation(string word,string abbr){
        int i=0,j=0; 
        while(i<word.length()&&j<abbr.length()){
            if(isdigit(abbr[j])){
                int start=j;
                while(j<abbr.length() &&isdigit(abbr[j]))
                {j++;}
                int num=stoi(abbr.substr(start,j-start));
                if(num==0 || (abbr[start] == '0' && j - start > 1)) return false;
                i+=num;
                }
            else{
                if(word[i]!=abbr[j]) return false;
                i++;
                j++;
            }
        }
        return i==word.length()&&j==abbr.length();
    }
};