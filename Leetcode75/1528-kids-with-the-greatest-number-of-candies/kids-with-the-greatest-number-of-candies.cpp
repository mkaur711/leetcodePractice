class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max=*max_element(candies.begin(),candies.end());
        vector<bool> res;
        for(int i=0;i<candies.size();i++){
            if((extraCandies+candies[i])>=max){
                res.push_back(true);
            }
            else{
                res.push_back(false);
            }
        }
        return res;
    }
        /*
          // Find the maximum number of candies any kid currently has
        int maxCandies = *max_element(candies.begin(), candies.end());
        
        // Initialize the result vector
        vector<bool> res;
        
        // Determine if each kid can have the greatest number of candies
        for(int candy : candies) {
            res.push_back(candy + extraCandies >= maxCandies);
        }
        
        return res;
        */
};