class Solution {
public:
    int dr[4] = {1, 0, 0, -1};
    int dc[4] = {0, 1, -1, 0};

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        dist[0][0] = grid[0][0];

        priority_queue<array<int,3>, vector<array<int,3>>, greater<>> pq;
        pq.push({grid[0][0], 0, 0});

        while(!pq.empty()) {
            auto [t, r, c] = pq.top();
            pq.pop();

            if(r == n-1 && c == n-1) return t; // reached target

            for(int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr >= 0 && nc >= 0 && nr < n && nc < n) {
                    int newTime = max(t, grid[nr][nc]);
                    if(newTime < dist[nr][nc]) {
                        dist[nr][nc] = newTime;
                        pq.push({newTime, nr, nc});
                    }
                }
            }
        }
        return -1; 
    }
};
