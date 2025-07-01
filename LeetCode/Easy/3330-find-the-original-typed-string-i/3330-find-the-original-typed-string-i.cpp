class Solution {
public:
    int possibleStringCount(string word) {
        int result = 1; 
        int i = 0, n = word.length();

        while (i < n) {
            int j = i;
            while (j < n && word[j] == word[i]) {
                j++;  
            }
            int len = j - i-1;
            result += len;  
            i = j;
        }

        return result;
    }
};
