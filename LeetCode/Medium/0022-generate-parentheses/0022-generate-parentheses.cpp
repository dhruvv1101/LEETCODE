class Solution {
public:
    vector<string>res;
    bool isval(string s){
        int o=0;
        for(auto it:s){
            if(it=='('){
                o++;
            }else{
                o--;
                if(o<0){
                    return 0;
                }
            }
        }
        return o==0;
    }
    void solve(int n,string &s){
        if(s.length()==2*n){
            if(isval(s)){
                res.push_back(s);
            }
            return;
        }
        s.push_back('(');
        solve(n,s);
        s.pop_back();
        s.push_back(')');
        solve(n,s);
        s.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        string cur="";
        solve(n,cur);
        return res;
    }
};