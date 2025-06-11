class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<int>cities(n);
        vector<vector<int>>dist(n,vector<int>(n,INT_MAX));
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];
            dist[u][v]=wt;
            dist[v][u]=wt;
        }
        for(int i=0;i<n;i++){
            dist[i][i]=0;
        }


        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                      if(dist[i][k]==INT_MAX || dist[k][j]==INT_MAX) continue;
                    dist[i][j]=min(dist[i][j] , dist[i][k] + dist[k][j]);
                }
            }
        }
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<n;j++){
                if(dist[i][j]>0 && dist[i][j]<=distanceThreshold) count++;
            }
            cities[i]=count;
        }
        int index=-1;
        int mincount=INT_MAX;
        for(int i=0;i<n;i++){
            if(cities[i]<=mincount){
                mincount=cities[i];
                index=max(index,i);
            }
        }
        return index;
    }
};