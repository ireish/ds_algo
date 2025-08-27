// Method 1 - Using Min-Heap

class Interval {
    int start;
    int end;
    Interval(int s, int e) {
        start = s;
        end = e;
    }
};


class Solution {
    public int minMeetingRooms(int[][] intervals) {

        // Sort the intervals by start time
        Arrays.sort( intervals, (a, b) -> Integer.compare(a[0], b[0]) );

        int n = intervals.length;

        // Min Heap based on end time so that we have track of earliest ending meeting until now
        var pq = new PriorityQueue<Interval>( (Interval a, Interval b) -> Integer.compare(a.end, b.end) );

        pq.offer(new Interval(intervals[0][0], intervals[0][1]));


        for(int i = 1; i < n; i++) {
            Interval earliest = pq.peek();
            int curStart = intervals[i][0];
            int curEnd = intervals[i][1];

            // Can optimize below if else; Intentially kept it for algorithm clarity
            // If current meeting starts before earliest ending meeting ends, we need a new room
            if(curStart < earliest.end) {
                pq.offer(new Interval(curStart, curEnd));
            }
            // Else we can reuse the same room, so we remove the earliest ending meeting and add the current meeting
            else {
                pq.poll();
                pq.offer(new Interval(curStart, curEnd));
            }
        }

        return pq.size();        
    }
}