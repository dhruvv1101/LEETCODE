class Solution {
public:
    int maximumDifference(vector<int>& a) {
        int d=INT_MIN;
        int el=a[0];
        for(int i=1;i<a.size();i++){
            if(a[i]<el){
                el=a[i];
            }
            else{
                d=max(d,a[i]-el);
            } 
        }
        return d<=0?-1:d;
    }
};