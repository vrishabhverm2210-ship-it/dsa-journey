
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        int n = intervals.size();
        if (n == 0) return 0;

        int count = 0;
        int end = intervals[0][1];

        for (int i = 1; i < n; i++) {
            if (intervals[i][0] < end) {
                // Overlap: remove one interval
                count++;
                end = min(end, intervals[i][1]);
            } else {
                // No overlap: keep this interval
                end = intervals[i][1];
            }
        }

        return count;
    }
};

