class Solution {
    public int nearestDrone(int[][] drones, int[] target) {
        int n=drones.length;
        int mini=Integer.MAX_VALUE;
        int idx=-1;
     for(int i=0;i<n;i++){
        int distance = Math.abs(drones[i][0] - target[0])
                         + Math.abs(drones[i][1] - target[1]);

            if (distance <= drones[i][2]&&mini>distance) {
                mini=distance;
                idx=i;
            }
     }
     return idx;
    }
}