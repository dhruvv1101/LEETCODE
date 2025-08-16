class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0,m=INT_MIN;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            m=max(m,sum);
            if(sum<1){
                sum=0;
            }
        }
        return m;
    }
};