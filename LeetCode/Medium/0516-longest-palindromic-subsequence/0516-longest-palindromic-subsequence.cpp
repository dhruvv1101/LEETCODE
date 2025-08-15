class Solution {
public:
int t[1001][1001];
    int solve(string& s,string& r,int i,int j){
        if(i>=s.length()||j>=s.length()){
            return 0;
        }
        if(t[i][j]!=-1){
            return t[i][j];
        }
        if(s[i]==r[j])return t[i][j]=1+solve(s,r,i+1,j+1);
        return t[i][j]=max(solve(s,r,i+1,j),solve(s,r,i,j+1));
    }
    int longestPalindromeSubseq(string s) {
        string r=s;
        memset(t,-1,sizeof(t));
        reverse(r.begin(),r.end());
        return solve(s,r,0,0);
    }
};