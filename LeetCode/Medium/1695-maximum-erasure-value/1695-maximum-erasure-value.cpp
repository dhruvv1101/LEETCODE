class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = 0, sum = 0, maxSum = 0;
        unordered_map<int, int> mpp;

        while (r < n) {
            if (mpp.find(nums[r]) != mpp.end()) {
                // Shrink the window from left and subtract from sum
                while (l <= mpp[nums[r]]) {
                    sum -= nums[l];
                    l++;
                }
            }

            sum += nums[r];
            maxSum = max(maxSum, sum);
            mpp[nums[r]] = r;
            r++;
        }

        return maxSum;
    }
};