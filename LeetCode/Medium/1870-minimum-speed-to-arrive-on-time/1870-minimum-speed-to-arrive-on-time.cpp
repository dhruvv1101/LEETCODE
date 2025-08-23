class Solution {
public:
using ll=long long;
bool solve(ll speed,double hour,vector<int>& dis){
    double total = 0;
    int n = dis.size();
    for (int i = 0; i < n; i++) {
    if (i != n - 1) {
        total += ceil((double)dis[i] / speed);
    } else {
        total += (double)dis[i] / speed;
    }
}
return total <= hour;
}
    int minSpeedOnTime(vector<int>& dis, double hour) {
       
        int n=dis.size();
        if(hour<n-1){
            return -1;
        }
        ll l=1,h=1e7;
        ll ans=-1;
        while(l<=h){
             ll mid=l+(h-l)/2;
            if(solve(mid,hour,dis)){
                ans=mid;
                h=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
};