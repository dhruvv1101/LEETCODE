class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int n=s1.length();
        int m=s2.length();
        int t[1001][1001];
        for(int i=0;i<n;i++){
            t[i][0]=0;
        }
        for(int i=0;i<m;i++){
            t[0][i]=0;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]) t[i][j]=1+t[i-1][j-1];
                else t[i][j]=max(t[i-1][j],t[i][j-1]);
            }
        }
        return t[n][m];
    }
};