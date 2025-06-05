class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string>b(bank.begin(),bank.end());
        unordered_set<string>vis;
        queue<string>q;
        q.push(start);
        vis.insert(start);
        int level=0;
        while(!q.empty()){
            int n=q.size();
            while(n--){
                string cur=q.front();
                q.pop();
                if(cur==end)return level;
                for(char ch:"ACGT"){
                    for(int i=0;i<cur.size();i++){
                        string nei=cur;
                        nei[i]=ch;
                        if(vis.find(nei)==vis.end()&&b.find(nei)!=b.end()){
                            q.push(nei);
                            vis.insert(nei);
                        }
                    }
                }
            }
             level++;
        }
        return -1;
    }
};