class Solution {
public:
    int longestSubsequence(string s, int k) {
       int n=s.length();
       int cnt=0;
       long long pow2=1;
       for(int i=n-1;i>=0;i--){
        if(s[i]=='0'){
            cnt++;
        }else if(pow2<=k){
            k-=pow2;
            cnt++;
        }
        if(pow2<=k){
            pow2<<=1;
        }
       }
       return cnt;
    }
};