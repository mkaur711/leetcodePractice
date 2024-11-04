#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0; // No meetings means no rooms needed

        // Create a min-heap to track end times of meetings
        priority_queue<int, vector<int>, greater<int>> minHeap;

        // Sort the meetings in increasing order of their start times
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });

        // Add the first meeting's end time to the heap
        minHeap.push(intervals[0][1]);

        // Iterate over the remaining meetings
        for (int i = 1; i < intervals.size(); i++) {
            // If the meeting can start after the earliest ending meeting
            if (intervals[i][0] >= minHeap.top()) {
                minHeap.pop(); // Reuse the room
            }
            // Add the current meeting's end time to the heap
            minHeap.push(intervals[i][1]);
        }

        // The size of the heap tells us the minimum rooms required
        return minHeap.size();
    }
};
