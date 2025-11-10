class Solution {
public:
    int minOperations(vector<int>& nums) {
        nums.push_back(0);
        vector<int>s;
        int c=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            while(!s.empty()){
                if(nums[i]>s.back()){
                    s.push_back(nums[i]);
                    break;
                }else if(nums[i]<s.back()){
                    s.pop_back();
                    c++;
                }else{
                    break;
                }
            }
            if(s.empty()&&nums[i]!=0){
            s.push_back(nums[i]);
        }
        }
        return c;
    }
    
};