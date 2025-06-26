class Solution {
public:
    int earliestFullBloom(vector<int>& pt, vector<int>& gt) {
        int n =pt.size();
        vector<pair<int,int>>a(n);
        for(int i=0;i<n;i++){
            a[i].first=gt[i];
            a[i].second=pt[i];
        }
        sort(a.begin(),a.end());
        reverse(a.begin(),a.end());
        int maxbloom=0;
        int prvp=0;
        for(int i=0;i<n;i++){
            int curpt=a[i].second;
            int curgt=a[i].first;
            prvp+=curpt;
            int bloomtime=prvp+curgt;
            maxbloom=max(maxbloom,bloomtime);
        }
        return maxbloom;
    }
};