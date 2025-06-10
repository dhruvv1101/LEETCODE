class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Step 1: Build adjacency list as (node -> list of (neighbour, weight))
        unordered_map<int, vector<pair<int, int>>> adj;
        for (auto& e : times) {
            int u = e[0];
            int v = e[1];
            int w = e[2];
            adj[u].push_back({v, w});
        }

        // Step 2: Dijkstra's algorithm using min-heap priority queue
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        vector<int> dist(n + 1, INT_MAX);  // 1-based indexing
        dist[k] = 0;
        pq.push({0, k});

        while (!pq.empty()) {
            auto [d, node] = pq.top();
            pq.pop();

            for (auto& [nei, wt] : adj[node]) {
                if (d + wt < dist[nei]) {
                    dist[nei] = d + wt;
                    pq.push({dist[nei], nei});
                }
            }
        }

        // Step 3: Calculate the maximum time to reach any node
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (dist[i] == INT_MAX) return -1;
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};
