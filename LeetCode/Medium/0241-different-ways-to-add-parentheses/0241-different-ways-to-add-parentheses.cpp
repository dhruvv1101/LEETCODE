class Solution {
public:
    vector<int>solve(string s){
        vector<int>res;
        for(int i=0;i<s.size();i++){
            if(s[i]=='+'||s[i]=='-'||s[i]=='*'){
                vector<int>lp=solve(s.substr(0,i));
                vector<int>rp=solve(s.substr(i+1));
                for(auto il:lp){
                    for(auto ir:rp){
                        if(s[i]=='+'){
                            res.push_back(il+ir);
                        }else if(s[i]=='*'){
                            res.push_back(il*ir);
                        }else{
                            res.push_back(il-ir);
                        }
                    }
                }
            }
        }
        if(res.empty()){
            res.push_back(stoi(s));
        }
        return res;
    }
    vector<int> diffWaysToCompute(string s) {
        return solve(s);
    }
};