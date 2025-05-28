class Solution {
public:
    bool issafe(int xn ,int yn,int n,int m){
        return xn>=0&&xn<n&&yn>=0&&yn<m;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        if(n==0||m==0||grid[0][0]!=0){
            return -1;
        }
        vector<vector<int>>dir={{1,1},{1,0},{0,1},{-1,1},{1,-1},{-1,-1},{-1,0},{0,-1}};// rd r d ld ru lu l u 
        queue<pair<int,int>>q;
        q.push({0,0});
        grid[0][0]=1;
        int level=0;
        while(!q.empty()){
            int N=q.size();
            while(N--){
                auto cur=q.front();
                q.pop();
                int x=cur.first;
                int y=cur.second;
                if(x==n-1&&y==m-1){
                    return level+1;
                }
                for(auto d:dir){
                    int xn=x+d[0];
                    int yn=y+d[1];
                    if(issafe(xn,yn,n,m)&&grid[xn][yn]==0){
                        grid[xn][yn]=level+1;
                        q.push({xn,yn});
                    }
                }
            }
            level++;
        }
        return -1;
    }
};