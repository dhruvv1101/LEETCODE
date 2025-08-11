class Solution {
public:
int n;
int t[301][5001];
    int solve(int c,int amount, vector<int>& coins){
        if(amount==0){
            return 1;
        }
        if(t[c][amount]!=-1){
            return t[c][amount];
        }
        if(c==n){
            return 0;
        }
        if(coins[c]>amount){
            return t[c][amount]=solve(c+1,amount,coins);
        }
        int take=solve(c,amount-coins[c],coins);
        int skip=solve(c+1,amount,coins);
        return t[c][amount]=take+skip;
    }
    int change(int amount, vector<int>& coins) {
        n=coins.size();
        memset(t,-1,sizeof(t));
        return solve(0,amount,coins);
    }
};