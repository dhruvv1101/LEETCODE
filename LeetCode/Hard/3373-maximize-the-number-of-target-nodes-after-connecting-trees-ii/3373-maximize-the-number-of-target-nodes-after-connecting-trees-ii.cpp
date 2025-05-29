class Solution {
public:
    unordered_map<int,vector<int>>getadj(vector<vector<int>>& edges){
        unordered_map<int,vector<int>>adj;
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return adj;
    }
    void find(int start,unordered_map<int,vector<int>>&adj,int parent,int &zero,int &one,vector<int>&mark){
        if(mark[start]==0){
            zero++;
        }else{
            one++;
        }
        for(auto &nei :adj[start]){
            if(nei!=parent){
                mark[nei]=(mark[start]==0)?1:0;
                find(nei,adj,start,zero,one,mark);
            }
        }
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n=edges1.size()+1;
        int m=edges2.size()+1;
        //adj list
        unordered_map<int,vector<int>>adj1=getadj(edges1);
        unordered_map<int,vector<int>>adj2=getadj(edges2);
        //finding vector array max of tree two;
        int zerob=0,oneb=0;
        vector<int>ans2(m,-1);
        find(0,adj2,-1,zerob,oneb,ans2);
        int zeroa=0,onea=0;
        vector<int>ans1(n,-1);
        find(0,adj1,-1,zeroa,onea,ans1);
        int maxi=max(zerob,oneb);
        vector<int>result(ans1.size());
        for(int i=0;i<ans1.size();i++){
            int marking=ans1[i];
            if(marking==0){
                result[i]=zeroa+maxi;
            }else{
                result[i]=onea+maxi;
            }
        }
        return result;
    }
};
