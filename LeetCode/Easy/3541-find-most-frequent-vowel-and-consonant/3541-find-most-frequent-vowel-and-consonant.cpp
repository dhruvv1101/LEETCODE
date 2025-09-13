class Solution {
public:
    bool isvowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    int maxFreqSum(string s) {
        int total = 0;
        unordered_map<char, int> mpp;
        for (auto it : s) {
            mpp[it]++;
        }

        int mv = 0;
        int mc = 0;

        for (auto it : mpp) {
            if (isvowel(it.first)) {
                mv = max(mv, it.second);
            } else if (isalpha(it.first)) {
                mc = max(mc, it.second);
            }
        }

        return mv+mc;
    }
};
