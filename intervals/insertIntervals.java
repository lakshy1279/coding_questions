// You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval and intervals is sorted in ascending order by starti. You are also given an interval newInterval = [start, end] that represents the start and end of another interval.

// Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).

// Return intervals after the insertion.

// Note that you don't need to modify intervals in-place. You can make a new array and return it.
//Link:https://leetcode.com/problems/insert-interval/description/


class Solution {
    //() ||
    public int[][] insert(int[][] intervals, int[] newInterval) {
       List<int []> res = new ArrayList<>();
       int i = 0;
       int n = intervals.length;
       // STEP:1
       // insert those intervals which are smaller that newinterval
       // if intervals[i][1] is smaller than by default intervals[i][0] is also smaller 
       // check not on intervals[i][0] as intervals[i][1] can be greater than newInterval[0]
       // so it can be the case of merging
       while( i < n && newInterval[0] > intervals[i][1]){
        res.add(intervals[i]);
        i++;
       }

       // STEP:2
       // merge the newInterval with intervals
       // now newInterval is smaller comapred to intervals[i][0] so condition 
       // work according to that ( newInterval , interval[i], interval[i + 1])
       while(i < n && newInterval[1] >= intervals[i][0]){
        newInterval[0] = Math.min(newInterval[0], intervals[i][0]);
        newInterval[1] = Math.max(newInterval[1], intervals[i][1]);
        i++;
       }

       // STEP: 3
       // insert the remaning intervals.
       res.add(newInterval);

       while(i < n){
        res.add(intervals[i]);
        i++;
       }
       return res.toArray(new int[res.size()][]);
    }
}