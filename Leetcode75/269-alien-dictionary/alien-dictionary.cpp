class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char,unordered_set<char>> graph;
        unordered_map<char,int> inDegree;

        for(string word:words){
            for(char c:word){
                inDegree[c]=0;
            }
        }

        for(int i=0;i<words.size()-1;i++){
            string first=words[i];
            string second=words[i+1];

            int minLength=min(first.size(),second.size());
            bool found=false;
            for(int j=0;j<minLength;j++){
                if(first[j]!=second[j]){
                    if(graph[first[j]].insert(second[j]).second){
                        inDegree[second[j]]++;
                    }
                    found=true;
                    break;
                }
            }
            if(!found && first.size()>second.size()) return "";
        }

        queue<char> q;
        for(auto& pair:inDegree){
            if(pair.second==0)
                q.push(pair.first);
        }

        string order;
        while(!q.empty()){
            char current=q.front();
            q.pop();
            order+=current;

            for(char neighbor: graph[current]){
                inDegree[neighbor]--;
                if(inDegree[neighbor]==0)
                    q.push(neighbor);
            }
        }

        if(order.size()==inDegree.size()) return order;
        return "";
    }

};