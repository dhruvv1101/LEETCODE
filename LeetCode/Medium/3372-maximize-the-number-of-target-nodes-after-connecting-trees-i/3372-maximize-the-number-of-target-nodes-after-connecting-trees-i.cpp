class Solution {
public:
    int bfs(int i, vector<vector<int>>& adj, int k) {
        int n = adj.size();
        queue<pair<int, int>> q;
        q.push({i, 0});
        vector<bool> visited(n, false);
        visited[i] = true;
        int cnt = 0;
        
        while (!q.empty()) {
            int cur = q.front().first;
            int dis = q.front().second;
            q.pop();

            if (dis > k) continue;
            cnt++;

            for (auto& nei : adj[cur]) {
                if (!visited[nei]) {
                    visited[nei] = true;
                    q.push({nei, dis + 1});
                }
            }
        }
        return cnt;
    }

    vector<int> calc(vector<vector<int>>& edges, int k) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n);

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> result(n);
        for (int i = 0; i < n; i++) {
            result[i] = bfs(i, adj, k);
        }

        return result;
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        vector<int> ans2 = calc(edges2, k - 1);
        vector<int> ans1 = calc(edges1, k);
        int maxi2 = *max_element(ans2.begin(), ans2.end());

        for (int i = 0; i < ans1.size(); i++) {
            ans1[i] += maxi2;
        }

        return ans1;
    }
};
