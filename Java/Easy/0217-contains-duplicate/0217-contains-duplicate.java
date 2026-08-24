class Solution {
    public boolean containsDuplicate(int[] nums) {
            Set <Integer> all=new HashSet<>();
            for(int n :nums){
                if(all.contains(n)){
                    return true;
                }
                all.add(n);
            }
            return all.size()!=nums.length;
    }
}