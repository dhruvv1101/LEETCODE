#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixSumCount;
        prefixSumCount[0] = 1;  // Base case: sum of 0 is one time (important for cases where the sum equals k from the start)
        int sum = 0;
        int totalSubarrays = 0;

        for (int num : nums) {
            sum += num;  // Update the cumulative sum

            // If sum - k exists in the map, it means we've found a subarray with sum k
            if (prefixSumCount.find(sum - k) != prefixSumCount.end()) {
                totalSubarrays += prefixSumCount[sum - k];
            }

            // Update the prefixSumCount with the current sum
            prefixSumCount[sum]++;
        }

        return totalSubarrays;
    }
};
