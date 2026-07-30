class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int cnt = 0;
        int mcnt = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == 1) {
                cnt++;
                mcnt = Math.max(mcnt, cnt);
            } else {
                cnt = 0;
            }
        }
        
        return mcnt;
    }
}