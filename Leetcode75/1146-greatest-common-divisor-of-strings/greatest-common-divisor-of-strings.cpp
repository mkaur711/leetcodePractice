class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int l1= str1.length();
        int l2= str2.length();
        int l=0;
        string ans="";
        if(str1 + str2 != str2 + str1)
            return "";
        return str1.substr(0, gcd(str1.size(), str2.size()));

        if(l1<l2 || l2<l1){
            if(l1%l2==0){
                while(l<l2){
                    ans+=str2[l];
                    l++;
                }
            }

            if(l2%l1==0){
                while(l<l1){
                    ans+=str1[l];
                    l++;
                }
            }
            
        }
        return ans;
    }
};