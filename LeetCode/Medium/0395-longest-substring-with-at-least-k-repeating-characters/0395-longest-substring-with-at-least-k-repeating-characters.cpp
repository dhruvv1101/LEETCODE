class Solution {
public:
    int longestSubstring(string s, int k) {
        return helper(s, 0, s.size(), k);
    }

    int helper(string &s, int l, int r, int k) {
        unordered_map<char, int> freq;

        for (int i = l; i < r; ++i) {
            freq[s[i]]++;
        }

        for (int i = l; i < r; ++i) {
            if (freq[s[i]] < k) {
                int j = i + 1;
                while (j < r && freq[s[j]] < k) j++;
                return max(helper(s, l, i, k), helper(s, j, r, k));
            }
        }

        return r - l;
    }
};
