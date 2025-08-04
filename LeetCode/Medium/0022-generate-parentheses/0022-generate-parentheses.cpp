class Solution {
public:
    vector<string>res;
    
    void solve(int n,string &s,int o,int c){
        if(s.length()==2*n){
                res.push_back(s);
            return;
        }
        if(o<n){
        s.push_back('(');
        solve(n,s,o+1,c);
        s.pop_back();}
        if(c<o){
        s.push_back(')');
        solve(n,s,o,c+1);
        s.pop_back();}
    }
    vector<string> generateParenthesis(int n) {
        string cur="";
        int o=0,c=0;
        solve(n,cur,o,c);
        return res;
    }
};