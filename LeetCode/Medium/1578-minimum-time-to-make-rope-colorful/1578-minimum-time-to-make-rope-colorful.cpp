class Solution {
public:
    int minCost(string colors, vector<int>& time) {
        int n = colors.length();
        int cost = 0;
        int maxtime = time[0];

        for (int i=1;i<n;i++) {
            if (colors[i]==colors[i-1]) {
                //store max time for each island save it rest add all to removal
                cost+=min(maxtime,time[i]);
                maxtime=max(maxtime, time[i]);
            } else {
                maxtime = time[i]; // Reset maxTime for the new color group
            }
        }

        return cost;
    }
};