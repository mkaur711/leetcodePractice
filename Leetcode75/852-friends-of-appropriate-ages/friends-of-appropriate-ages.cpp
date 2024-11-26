class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int n = ages.size();
        vector<int> v(121,0);
        for(int i=0;i<n;i++){
            v[ages[i]]++;
        }
        int ans = 0;
        for(int x = 1; x <= 120; x++){
            int n1 = v[x];
            for(int y = 1; y <= 120; y++){
                int n2 = v[y];
                if(!(y <= (0.5 * x + 7) || y > x || ( y > 100 && x < 100))){
                    ans += n1*n2;
                    if(x==y){
                        ans -= n1;
                    }
                }
            }
        }
        return ans;
        
    }
};