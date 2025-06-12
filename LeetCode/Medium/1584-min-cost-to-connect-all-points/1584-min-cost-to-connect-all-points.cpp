class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int v = points.size();

        // ✅ Correct adj list declaration: vector of vectors of pairs
        vector<vector<pair<int,int>>> adj(v);

        // ✅ Build complete graph with Manhattan distances
        for(int i = 0; i < v; i++) {
            for(int j = i + 1; j < v; j++) {
                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];
                int d = abs(x1 - x2) + abs(y1 - y2);

                adj[i].push_back({j, d});
                adj[j].push_back({i, d});
            }
        }

        // ✅ Min-heap: {weight, {node, parent}}
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;

        vector<bool> vis(v, false);
        vector<int> parent(v, -1); // Optional if you want to track MST edges

        pq.push({0, {0, -1}});
        long long sum = 0;

        while (!pq.empty()) {
            auto [wt, p] = pq.top();         // wt = weight
            auto [node, par] = p;
            pq.pop();

            if (vis[node]) continue;

            vis[node] = true;
            sum += wt;
            parent[node] = par;

            for (auto &nbr : adj[node]) {
                int adjNode = nbr.first;
                int edgeWt = nbr.second;

                if (!vis[adjNode]) {
                    pq.push({edgeWt, {adjNode, node}});
                }
            }
        }

        return sum;
    }
};
