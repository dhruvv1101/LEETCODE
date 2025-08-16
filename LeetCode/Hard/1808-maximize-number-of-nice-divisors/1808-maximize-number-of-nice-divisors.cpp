class Solution {
public:
    const long long mod = 1e9 + 7;

    long long modPow(long long base, long long exp) {
        long long res = 1;
        while (exp > 0) {
            if (exp & 1) res = (res * base) % mod;
            base = (base * base) % mod;
            exp >>= 1;
        }
        return res;
    }

    int maxNiceDivisors(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        if (n == 3) return 3;

        long long k = n / 3;
        int y = n % 3;

        if (y == 0) {
            return modPow(3, k);
        }
        if (y == 1) {
            return (modPow(3, k - 1) * 4) % mod;
        }
        return (modPow(3, k) * 2) % mod;
    }
};
