class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        const int MOD = 1e9 + 7;
        vector<int> power, res;

        for (int i = 0; i < 32; i++) {
            if ((n & (1 << i)) != 0) {
                power.push_back(1 << i);
            }
        }

        for (auto &it : queries) {
            int s = it[0], e = it[1];
            long long pr = 1;
            for (int i = s; i <= e; i++) {
                pr = (pr * power[i]) % MOD;
            }
            res.push_back((int)pr);
        }
        return res;
    }
};
