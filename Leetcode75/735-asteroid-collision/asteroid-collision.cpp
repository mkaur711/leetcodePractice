class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> stack;
        for(int asteroid:asteroids){
            bool survives=true;
            while(!stack.empty()&&asteroid<0&&stack.back()>0){
                if(abs(stack.back())<abs(asteroid)){
                    stack.pop_back();

                }
                else if(abs(stack.back())==abs(asteroid)){
                    stack.pop_back();
                    survives=false;
                    break;
                }
                else{
                    survives=false;
                    break;
                }
            }
            if(survives){
                stack.push_back(asteroid);
            }
        }
        return stack;}
};