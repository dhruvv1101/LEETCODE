class Solution {
public:
vector<int>parent;
vector<int>rank;
    int find(int x){
        if(x==parent[x]){
            return x;
        }
        return parent[x]=find(parent[x]);
    }
    void unions(int x,int y){
        int px=find(x);
        int py=find(y);
        if(px==py)return;
        if(px>py){
            parent[px]=py;
        }else if(py>px){
            parent[py]=px;
        }else{
            parent[py]=px;
            rank[px]++;
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        parent.resize(n);
        if(connections.size()<n-1){
            return -1;
        }
        rank.resize(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        int com=n;
        for(auto &v:connections){
            if(find(v[0])!=find(v[1])){
                unions(v[0],v[1]);
                com--;
            }
        }
        return com-1;
    }
};