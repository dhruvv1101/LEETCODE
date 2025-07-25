#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maxSum(vector<int>& nums) {
    int ans = 0;
    bool flag = false;
    int val = INT_MIN;
    set<int> st;
    
    for (auto it : nums) {
        st.insert(it);
    }
    
    for (auto it : st) {
        if (it > 0) {
            flag = true;
            ans += it;
        } else {
            val = max(val, it);
        }
    }
    
    if (flag) 
        return ans;
    
    return val;
}

};
