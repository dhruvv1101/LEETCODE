class Solution {
public:
vector<int> generaterow(int rownum){
    vector<int>ansrow;
    ansrow.push_back(1);
    long long ans=1;
    for(int i=1;i<rownum;i++){
        ans*=(rownum-i);
        ans/=i;
        ansrow.push_back(ans);
    }
    return ansrow;
}
    vector<vector<int>> generate(int num) {
        vector<vector<int>>ans;
        for(int i=1;i<=num;i++){
            vector<int>temp=generaterow(i);
            ans.push_back(temp);
        }
        return ans;

    }
};