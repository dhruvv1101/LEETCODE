class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        int md = INT_MAX;
        unordered_map<int , vector<int>> mpp;
        
        for (int i = 0; i < n; i++) {
            mpp[nums[i]].push_back(i);
        }

        for (auto& [val , idx] : mpp) {
            if (idx.size() < 3) continue;
            for (int i = 0; i + 2 < idx.size(); i++) {
                int dist = 2 * (idx[i + 2] - idx[i]);
                md = min(md , dist);
            }
        }
        return md == INT_MAX ? -1 : md;
    }
};