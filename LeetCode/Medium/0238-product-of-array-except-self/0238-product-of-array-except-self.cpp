class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        int c0=0;

        long long overall=1;
        c0=count(nums.begin(),nums.end(),0);
        for(int i=0;i<n;i++){
            if(nums[i]){
                overall*=nums[i];
            }
        }

        for(int i=0;i<n;i++){
            if(c0>1){
                nums[i]=0;
            }else if(c0==1){
                nums[i]=nums[i]==0? overall:0;
            }else{
                nums[i]=overall/nums[i];
            }
        }
        return nums;
    }
};