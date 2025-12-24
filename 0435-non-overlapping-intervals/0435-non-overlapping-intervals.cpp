class Solution {
public:
    /*First, we sort the intervals based on their end times (the second element
    of each interval). Then, we initialize the end variable with the end time of
    the first interval. Next, we iterate through the intervals from the second
    one onward, and for each interval, we check if its start time is greater
    than or equal to the current end.*/
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });
        int end = intervals[0][1];
        int count = 0;
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < end) {
                count++;
            } else {
                end = intervals[i][1];
            }
        }
        return count;
    }
};