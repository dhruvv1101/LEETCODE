class Solution {
public:
    bool checkValidString(string s) {
        int mino=0,mine=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                mino++,mine++;
            }
            else if(s[i]==')'){
                mino--,mine--;
            }else{
                mino--,mine++;
            }
            if(mine<0)return false;
            mino=max(0,mino);
        }
        return mino==0;
    }
};
