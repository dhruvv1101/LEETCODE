typedef pair<int, pair<int, int>> p;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& h) {
        int m = h.size();
        int n = h[0].size();
        vector<vector<int>> dir = {{-1,0},{1,0},{0,1},{0,-1}};
        vector<vector<int>> result(m, vector<int>(n, INT_MAX));
        priority_queue<p, vector<p>, greater<p>> pq;
        result[0][0] = 0;
        pq.push({0, {0, 0}});

        while (!pq.empty()) {
            auto [d, cor] = pq.top();
            pq.pop();
            int r = cor.first;
            int c = cor.second;
            for (auto e : dir) {
                int nr = r + e[0];
                int nc = c + e[1];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    int dif = abs(h[r][c] - h[nr][nc]);
                    int mdif = max(d, dif);
                    if (result[nr][nc] > mdif) {
                        result[nr][nc] = mdif;
                        pq.push({mdif, {nr, nc}});
                    }
                }
            }
        }
        return result[m-1][n-1];
    }
};
