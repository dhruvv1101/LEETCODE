typedef pair<int, pair<int, int>> p;

class Solution {
public:
    bool issafe(int xn, int yn, int n, int m) {
        return xn >= 0 && xn < n && yn >= 0 && yn < m;
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        if (n == 0 || m == 0 || grid[0][0] != 0 || grid[n - 1][m - 1] != 0)
            return -1;

        vector<vector<int>> dir = {{1,1},{1,0},{0,1},{-1,1},{1,-1},{-1,-1},{-1,0},{0,-1}};
        vector<vector<int>> result(n, vector<int>(m, INT_MAX));
        priority_queue<p, vector<p>, greater<p>> pq;

        pq.push({1, {0, 0}});
        result[0][0] = 1;

        while (!pq.empty()) {
            auto [dist, node] = pq.top();
            pq.pop();
            int x = node.first;
            int y = node.second;

            if (x == n - 1 && y == m - 1) return dist;

            for (auto& dxy : dir) {
                int xn = x + dxy[0];
                int yn = y + dxy[1];

                if (issafe(xn, yn, n, m) && grid[xn][yn] == 0 && dist + 1 < result[xn][yn]) {
                    result[xn][yn] = dist + 1;
                    pq.push({result[xn][yn], {xn, yn}});
                }
            }
        }

        return -1;
    }
};
