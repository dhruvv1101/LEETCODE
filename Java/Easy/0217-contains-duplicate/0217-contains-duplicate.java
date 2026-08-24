class Solution {
    public boolean containsDuplicate(int[] nums) {
            Set <Integer> all=new HashSet<>();
            for(int n :nums){
                all.add(n);
            }
            return all.size()!=nums.length;
    }
}