class Solution {
public:
    int piv(vector<int>& nums,int l ,int r){
        int pi=nums[l];
        int i=l+1;
        int j=r;
        while(i<=j){
            if(nums[i]<pi&&nums[j]>pi){
                swap(nums[i],nums[j]);
                i++;
                j--;
            }
            if(nums[i]>=pi){
                i++;
            }
            if(nums[j]<=pi){
                j--;
            }
        }
        swap(nums[l],nums[j]);
        return j;
    }
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        int l=0;
        int r=n-1;
        int pi=-1;
        while(true){
             pi=piv(nums,l,r);
            if(pi==k-1){
                break;
            }else if(pi>k-1){
                r=pi-1;
            }else{
                l=pi+1;
            }
        }
        return nums[pi];
    }
};