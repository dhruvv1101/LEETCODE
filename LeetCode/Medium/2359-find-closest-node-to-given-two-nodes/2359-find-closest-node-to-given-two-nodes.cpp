class Solution {
public:
    void bfs(int node,unordered_map<int,vector<int>>&adj,vector<int>&dis){
        queue<int>q;
        dis[node]=0;
        q.push(node);
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(int v:adj[u]){
                if(dis[v]==-1){
                    dis[v]=dis[u]+1;
                    q.push(v);
                }
            }
        }

    }
    int closestMeetingNode(vector<int>& nums, int node1, int node2) {
        unordered_map<int,vector<int>>adj;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]!=-1){
            adj[i].push_back(nums[i]);}
        }
        vector<int>dis1(n,-1),dis2(n,-1);
        bfs(node1,adj,dis1);
        bfs(node2,adj,dis2);
        int ans=-1;
        int minmaxdis=INT_MAX;
        for(int i=0;i<n;i++){
            if(dis1[i]!=-1&&dis2[i]!=-1){
                int maxdis=max(dis1[i],dis2[i]);
                if(maxdis<minmaxdis){
                    minmaxdis=maxdis;
                    ans=i;
                }
            }
        }
        return ans;
    }
};