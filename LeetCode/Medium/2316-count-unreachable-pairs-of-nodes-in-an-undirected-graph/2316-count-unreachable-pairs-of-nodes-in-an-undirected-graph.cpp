class Solution {
public:
vector<int>parent,rank;

    int find(int x){
        if(x==parent[x]){
            return x;
        }
        return parent[x]=find(parent[x]);
    }
    void unions(int x,int y){
        int px=find(x);
        int py=find(y);
        if(px==py){
            return;
        }
        if(rank[px]>rank[py]){
            parent[px]=py;
        }
        else if(rank[px]<rank[py]){
            parent[py]=px;
        }else{
            parent[py]=px;
            rank[px]++;
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        for(auto&ve:edges){
            int u=ve[0];
            int v=ve[1];
            unions(u,v);
        }
        unordered_map<int,int>mpp;
        for(int i=0;i<n;i++){
            int x=find(i);
            mpp[x]++;
        }
        long long result=0;
        long long rem =n;
        for(auto &i :mpp){
            rem-=i.second;
            result+=(i.second)*(rem);
        }
        return result;
    }
};