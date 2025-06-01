class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l=0;
        int n=matrix.size();
        int m=matrix[0].size();
        int r=n*m-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(matrix[mid/m][mid%m]>target){//mid repesent index in 1D array 
            //convert it to 2 D array using {r=mid/no of col} {c=mid%no of col}
                r=mid-1;
            }else if(matrix[mid/m][mid%m]<target){
                l=mid+1;
            }else{
                return true;
            }
        }
        return false;

    }
};