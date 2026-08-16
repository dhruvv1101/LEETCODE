class Solution {
    public boolean stoneGameIX(int[] stones) {
        int c1=0,c2=0,c0=0;
        for(int s:stones){
            if(s%3==0){
                c0++;
            }else if(s%3==1){
                c1++;
            }else{
                c2++;
            }
        }
        if((c0&1)==0){
            return Math.min(c1,c2)>0;
        }
        return Math.abs(c1-c2)>2;
    }
}