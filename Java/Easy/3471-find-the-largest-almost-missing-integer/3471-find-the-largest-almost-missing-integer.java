class Solution {
    public int largestInteger(int[] nums, int k) {
        int []f =new int[51];
        for(int x:nums){
            f[x]++;
        }
        int ans=-1,n=nums.length;
        for(int i=0;i<n;i++){
            if(k==n){
                ans=Math.max(ans,nums[i]);
            }else if(f[nums[i]]==1){
                if(k==1){
                    ans=Math.max(ans,nums[i]);
                }else if(i==0||i==n-1){
                    ans=Math.max(ans,nums[i]);
                }
            }
        }
        return ans;

    }
}