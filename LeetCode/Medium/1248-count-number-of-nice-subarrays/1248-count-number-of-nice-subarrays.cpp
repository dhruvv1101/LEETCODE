class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        int l=0,r=0;
        int oc=0,ec=0;
        int cnt=0;
        while(r<n){
            if(nums[r]&1){
                oc++;
            }
            while(l<r&&(oc>k||!(nums[l]&1))){
                if(nums[l]&1){
                    ec=0;
                }else{
                    ec++;
                }
                if(nums[l]&1){
                    oc--;
                }
                l++;
            }
            if(oc==k)
            cnt+=(1+ec);
            r++;
        }
        return cnt;
    }
};