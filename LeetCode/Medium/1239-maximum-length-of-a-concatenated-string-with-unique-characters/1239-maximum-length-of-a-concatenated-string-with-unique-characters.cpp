class Solution {
public:
    bool hasOverlap(string& a, string& b) {
        vector<int> freq(26, 0);
        for (char c : a) freq[c - 'a']++;
        for (char c : b) {
            if (freq[c - 'a'] > 0) return true;
        }
        return false;
    }

    bool isUnique(string& s) {
        vector<int> freq(26, 0);
        for (char c : s) {
            if (freq[c - 'a']++) return false;
        }
        return true;
    }

    int solve(int s, string formed, vector<string>& arr) {
        if (s == arr.size()) {
            return formed.size();
        }

        int take = 0, skip = 0;

        if (isUnique(arr[s]) && !hasOverlap(formed, arr[s])) {
            take = solve(s + 1, formed + arr[s], arr);
        }

        skip = solve(s + 1, formed, arr);

        return max(take, skip);
    }

    int maxLength(vector<string>& arr) {
        return solve(0, "", arr);
    }
};
