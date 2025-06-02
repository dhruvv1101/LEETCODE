class Solution {
public:
    int lengthOfLastWord(string s) {
        int idx=s.find_last_not_of(' ')+1;
        s.erase(idx);
        int lsp=s.find_last_of(' ');
        return s.length()-lsp-1;
    }
};