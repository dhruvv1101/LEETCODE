class Solution {
    public int minMoves(int[] nums) {
        return Arrays.stream(nums).sum()-nums.length*Arrays.stream(nums).min().getAsInt();
    }
}