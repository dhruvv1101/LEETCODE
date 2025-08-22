class Solution {
public:
    bool topo(unordered_map<int,vector<int>>&adj,int num,vector<int>&indegree){
        queue<int>q;
        int cnt=0;
        for(int i=0;i<num;i++){
            if(indegree[i]==0){
                cnt++;
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(auto &it:adj[u]){
                indegree[it]--;
                if(indegree[it]==0){
                    cnt++;
                    q.push(it);
                }
            }
        }
        return cnt==num;
    }
    bool canFinish(int num, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>>adj;
        vector<int>indegree(num,0);
        for(auto &v:prerequisites){
            int a=v[0];
            int b=v[1];
            //b--->a;
            adj[b].push_back(a);
            //arrow a me jarha h
            indegree[a]++;
        }
        return topo(adj,num,indegree);
    }
};