class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int,vector<pair<int,int>>>adj;
        for(auto &flight:flights){
            int u=flight[0];
            int v=flight[1];
            adj[u].push_back({v,flight[2]});
        }
        vector<int>dis(n,INT_MAX);
        queue<pair<int,int>>q;
        q.push({src,0});
        dis[src]=0;
        int step=0;
        while(!q.empty()&&step<=k){
            int n1=q.size();
            while(n1--){
                int u=q.front().first;
                int d=q.front().second;
                q.pop();
                for(auto it:adj[u]){
                    if(d+it.second<dis[it.first]){
                        dis[it.first]=d+it.second;
                        q.push({it.first,d+it.second});
                    }
                }
            }
            step++;
        }
        if(dis[dst]==INT_MAX){
            return -1;
        }
        return dis[dst];

    }
};