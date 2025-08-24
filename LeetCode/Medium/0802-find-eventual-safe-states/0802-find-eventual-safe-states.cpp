class Solution {
public:
    bool detcycle(int u,vector<int>&vis,vector<vector<int>>& g){
        vis[u]=1;
        for(auto v:g[u]){
            if(vis[v]==0){
                if(detcycle(v,vis,g)){
                    return true;
                }
            }else if(vis[v]==1){
                return true;
            }
        }
        vis[u]=2;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& g) {
        int n=g.size();
        vector<int>res,vis(n,0);
        for(int i=0;i<n;i++){
            if(!detcycle(i,vis,g)){
                res.push_back(i);
            }
        }
        return res;
    }
};