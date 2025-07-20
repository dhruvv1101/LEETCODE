class Solution {
public:
    int t[1001];

    int solve(vector<int>& nums, int i, int n) {
        if (i > n) return 0;
        if (t[i] != -1) return t[i];

        int steal = nums[i] + solve(nums, i + 2, n);
        int skip = solve(nums, i + 1, n);
        return t[i] = max(steal, skip);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        memset(t, -1, sizeof(t));
        int option1 = solve(nums, 0, n - 2);

        memset(t, -1, sizeof(t));
        int option2 = solve(nums, 1, n - 1);

        return max(option1, option2);
    }
};
