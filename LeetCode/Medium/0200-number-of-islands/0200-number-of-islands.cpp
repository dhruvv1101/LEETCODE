class Solution {
public:
    vector<int> parent, rank;

    int find(int x) {
        if (x != parent[x]) {
            parent[x] = find(parent[x]);  // Path compression
        }
        return parent[x];
    }

    void unions(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px == py) return;

        if (rank[px] < rank[py]) {
            parent[px] = py;
        } else if (rank[px] > rank[py]) {
            parent[py] = px;
        } else {
            parent[py] = px;
            rank[px]++;
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        parent.resize(n * m);
        rank.resize(n * m, 0);
        int count = 0;

        // Initialize DSU only for land cells
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    int id = i * m + j;
                    parent[id] = id;
                    count++;
                }
            }
        }

        // Directions: up, down, left, right
        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    int id1 = i * m + j;
                    for (auto [dx, dy] : dirs) {
                        int ni = i + dx, nj = j + dy;
                        if (ni >= 0 && ni < n && nj >= 0 && nj < m && grid[ni][nj] == '1') {
                            int id2 = ni * m + nj;
                            if (find(id1) != find(id2)) {
                                unions(id1, id2);
                                count--;
                            }
                        }
                    }
                }
            }
        }

        return count;
    }
};
