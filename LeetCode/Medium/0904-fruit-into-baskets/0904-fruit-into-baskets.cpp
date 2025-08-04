class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int mcnt=0;
        int cnt=0;
        int l=0;
        int r=0;
        map<int,int>mpp;
        int n=fruits.size();
        while(r<n){
            mpp[fruits[r]]++;
            while(mpp.size()>2){
                mpp[fruits[l]]--;
                if(mpp[fruits[l]]==0){
                    mpp.erase(fruits[l]);
                }
                l++;
            }
            cnt=max(cnt,r-l+1);
            r++;
        }
        return cnt;
    }
};