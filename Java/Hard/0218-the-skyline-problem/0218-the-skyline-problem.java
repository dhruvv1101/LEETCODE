class Solution {
    public List<List<Integer>> getSkyline(int[][] buildings) {

        List<List<Integer>> result = new ArrayList<>();

        // [x, index, type]
        // type = 1 -> building starts
        // type = -1 -> building ends
        List<int[]> events = new ArrayList<>();

        // Create events using original building array
        for (int i = 0; i < buildings.length; i++) {

            int left = buildings[i][0];
            int right = buildings[i][1];

            events.add(new int[]{left, i, 1});
            events.add(new int[]{right, i, -1});
        }

        // Sort events by x
        events.sort((a, b) -> {
            if (a[0] != b[0]) {
                return a[0] - b[0];
            }

            // At same x, process starts before ends
            return b[2] - a[2];
        });

        // [height, right]
        PriorityQueue<int[]> pq =
            new PriorityQueue<>((a, b) -> b[0] - a[0]);

        int previousMax = 0;
        int i = 0;

        while (i < events.size()) {

            int x = events.get(i)[0];

            // Process all events at the same x
            while (i < events.size() && events.get(i)[0] == x) {

                int buildingIndex = events.get(i)[1];
                int type = events.get(i)[2];

                int right = buildings[buildingIndex][1];
                int height = buildings[buildingIndex][2];

                if (type == 1) {
                    // Building starts
                    pq.add(new int[]{height, right});
                }

                i++;
            }

            // Remove buildings that have ended
            while (!pq.isEmpty() && pq.peek()[1] <= x) {
                pq.poll();
            }

            // Current tallest building
            int currentMax = pq.isEmpty() ? 0 : pq.peek()[0];

            // Skyline changes
            if (currentMax != previousMax) {

                result.add(Arrays.asList(x, currentMax));

                previousMax = currentMax;
            }
        }

        return result;
    }
}