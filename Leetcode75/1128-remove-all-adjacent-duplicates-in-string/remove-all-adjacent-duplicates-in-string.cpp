#include <string>
class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        for(auto c:s){
            if(!st.empty()&&st.top()==c){
                st.pop();
            }
            else{
                st.push(c);
            }
        }
        string res="";
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
         reverse(res.begin(), res.end());
        return res;
    }
};