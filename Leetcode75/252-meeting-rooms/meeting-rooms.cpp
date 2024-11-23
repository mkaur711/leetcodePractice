class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        // If there are no intervals, return true (no meetings to attend)
        if (intervals.empty()) return true;

        // Sort the intervals by the start time
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });

        // Loop through the sorted intervals and check for overlaps
        for (int i = 1; i < intervals.size(); i++) {
            // If the start time of the current meeting is less than the end time of the previous meeting, they overlap
            if (intervals[i][0] < intervals[i - 1][1]) {
                return false;
            }
        }
        return true; // No overlaps, return true
    }
};