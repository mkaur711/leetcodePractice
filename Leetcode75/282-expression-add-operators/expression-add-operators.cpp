class Solution {
public:

    void dfs(string num,int target,int pos,long current,long lastOperand,string expr,vector<string>&results){
        if(pos==num.size()){
            if(current==target)
                results.push_back(expr);
            return;
        }
        for(int i=pos;i<num.size();i++){
            string part=num.substr(pos,i-pos+1);
            long partVal=stol(part);
            if(part.size()>1&&part[0]=='0') break;
            if(pos==0){
                dfs(num, target, i + 1, partVal, partVal, part, results);
            }
            else{
                 dfs(num,target,i+1,current+partVal,partVal,expr+"+"+part,results);
                dfs(num,target,i+1,current-partVal,-partVal,expr+"-"+part,results);
                dfs(num,target,i+1,current-lastOperand+lastOperand*partVal,lastOperand*partVal,expr+"*"+part,results);

            }
        }
    }
    vector<string> addOperators(string num, int target) {
        vector<string> results;
        dfs(num,target,0,0,0,"",results);
        return results;
    }
};