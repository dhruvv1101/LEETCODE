class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mpp; // to store number and its index
        vector<int> result;

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            
            // Check if the complement exists in the map
            if (mpp.find(complement) != mpp.end()) {
                result.push_back(mpp[complement]); // Index of the complement
                result.push_back(i);               // Current index
                return result;                     // Return the result
            }
            
            // Store the current number with its index
            mpp[nums[i]] = i;
        }

        return result; // In case no solution is found
    }
};
