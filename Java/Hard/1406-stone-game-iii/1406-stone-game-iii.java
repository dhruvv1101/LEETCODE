class Solution {
    private int[] stoneValue;
    private Integer[] dp;
    private int n;

    public String stoneGameIII(int[] stoneValue) {
        this.stoneValue = stoneValue;
        this.n = stoneValue.length;
        this.dp = new Integer[n];

        int diff = maxDiff(0);

        if (diff > 0) return "Alice";
        if (diff < 0) return "Bob";
        return "Tie";
    }

    private int maxDiff(int i) {
        if (i == n) return 0;

        if (dp[i] != null) return dp[i];

        int best = Integer.MIN_VALUE;
        int sum = 0;

        // Take 1, 2, or 3 stones
        for (int k = 0; k < 3 && i + k < n; k++) {
            sum += stoneValue[i + k];
            best = Math.max(best, sum - maxDiff(i + k + 1));
        }

        return dp[i] = best;
    }
}