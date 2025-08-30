class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        const int num=9;
        bool r[num][num]={false};
        bool c[num][num]={false};
        bool b[num][num]={false};
        for(int i=0;i<num;i++){
            for(int j=0;j<num;j++){
                if(board[i][j]=='.'){
                    continue;
                }
                int idx=board[i][j]-'0'-1;
                int grid=(i/3)*3+(j/3);
                if(r[i][idx]||c[j][idx]||b[grid][idx]){
                    return false;
                }
                r[i][idx]=true;
                c[j][idx]=true;
                b[grid][idx]=true;
            }

        }
        return true;
        

    }
};