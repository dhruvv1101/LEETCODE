class Solution {
public:
    int t[301][301];
    const int mod = 1e9+7;

    int intPow(int base, int exp) {
        long long res = 1;
        for (int i = 0; i < exp; i++) {
            res *= base;
        }
        return (int)res;
    }

    int solve(int n, int x, int s) {
        if (n == 0) return 1;
        if (intPow(s, x) > n) return 0;

        if (t[n][s] != -1) return t[n][s];

        int rem = intPow(s, x);

        int take = solve(n - rem, x, s + 1);
        int skip = solve(n, x, s + 1);

        return t[n][s] = ( (long long)take + skip ) % mod;
    }

    int numberOfWays(int n, int x) {
        memset(t, -1, sizeof(t));
        return solve(n, x, 1);
    }
};
