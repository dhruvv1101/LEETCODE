class Solution {
public:
    void buildd(int node,int l,int r,int seg[],vector<int>&h){
        if(l==r){
            seg[node]=l;
            return;
        }
        int mid=(l+r)/2;
        buildd(node*2+1,l,mid,seg,h);
        buildd(node*2+2,mid+1,r,seg,h);
        int lin=seg[2*node+1];
        int rin=seg[2*node+2];
        seg[node]=(h[lin]>=h[rin])?lin:rin;
    }

    int *build(vector<int>&h,int n){
        int *seg=new int[4*n];
        buildd(0,0,n-1,seg,h);
        return seg;
    }

    int que(int s,int e,int node,int l,int r,int st[],vector<int>&h){
        if(l>e||r<s){
            return -1;
        }
        if(l>=s&&r<=e){
            return st[node];
        }
        int mid=(l+r)/2;
        int lin=que(s,e,2*node+1,l,mid,st,h);
        int rin=que(s,e,2*node+2,mid+1,r,st,h);

        if(lin==-1) return rin;
        if(rin==-1) return lin;
        return h[lin]>=h[rin]?lin:rin;
    }

    int rmiq(int st[],vector<int>&h,int n,int a,int b){
        return que(a,b,0,0,n-1,st,h);
    }

    vector<int> leftmostBuildingQueries(vector<int>& h, vector<vector<int>>& q) {
        int n=h.size();
        int *seg=build(h,n);
        vector<int>res;

        for(auto&qq:q){
            int maxin=max(qq[0],qq[1]);
            int minin=min(qq[0],qq[1]);

            if(maxin==minin){
                res.push_back(maxin);
                continue; // ✅ added to avoid duplicate push
            }
            if(h[maxin]>h[minin]){
                res.push_back(maxin);
                continue; // ✅ added to avoid duplicate push
            }

            int l=maxin+1;
            int r=n-1;
            int resin=INT_MAX;

            while(l<=r){
                int mid=(l+r)/2;
                int idx=rmiq(seg,h,n,l,mid);

                if(h[idx]>max(h[maxin],h[minin])){
                    resin=min(resin,idx);
                    r=mid-1; // ✅ check left half for leftmost index
                }else{
                    l=mid+1;
                }
            }

            if(resin==INT_MAX){
                res.push_back(-1);
            }else{
                res.push_back(resin);
            }
        }
        return res;
    }
};
