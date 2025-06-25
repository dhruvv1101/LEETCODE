class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
         map<vector<int>, int> mp;

        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < m; i++) {
            mp[grid[i]]++;
        }

        int count = 0;
        for (int i = 0; i < n; i++) {
            vector<int> v;
            for (int j = 0; j < m; j++) {
                v.push_back(grid[j][i]);
            }

            count += mp[v];
        }

        return count;
    }
};