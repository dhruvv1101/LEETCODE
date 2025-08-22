class Solution {
public:
    bool bfs(int node,vector<int>&par, unordered_map<int,vector<int>>&adj){
        queue<int>q;
        par[node]=1;
        q.push(node);
        while(!q.empty()){
            int cur=q.front();
            q.pop();
            for(auto it:adj[cur]){
                if(par[it]==par[cur]){
                    return 0;
                }
                if(par[it]==-1){
                    q.push(it);
                    par[it]=1-par[cur];
                }
            }
        }
        return 1;
    }
    bool possibleBipartition(int n, vector<vector<int>>& d) {
        unordered_map<int,vector<int>>adj;
        for(auto it:d){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>par(n+1,-1);
        for(int i=0;i<n;i++){
            if(par[i]==-1){
                if(!bfs(i,par,adj)){
                    return 0;
                }
            }
        }
        return 1;
    }
};