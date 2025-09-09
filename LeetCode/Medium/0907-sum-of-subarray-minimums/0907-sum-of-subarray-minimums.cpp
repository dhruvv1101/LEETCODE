class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> nse(n);  // Next Smaller Element
        vector<int> ple(n);  // Previous Less Element
        const int MOD = 1e9 + 7;

        // Compute Next Smaller Element (NSE)
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            nse[i] = st.empty() ? n : st.top(); // If no smaller element, set to n (out of bounds)
            st.push(i);
        }

        // Clear stack for PLE computation
        while (!st.empty()) {
            st.pop();
        }

        // Compute Previous Less Element (PLE)
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            ple[i] = st.empty() ? -1 : st.top(); // If no smaller element, set to -1
            st.push(i);
        }

        // Calculate sum using contribution formula
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            long long left = i - ple[i];   // Number of elements extending left
            long long right = nse[i] - i;  // Number of elements extending right
            sum = (sum + (arr[i] * left * right) % MOD) % MOD;
        }

        return sum;
    }
};