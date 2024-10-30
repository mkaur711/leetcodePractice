class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Max heap to store points by their distance to the origin
        priority_queue<pair<int, vector<int>>> maxHeap;

        for (auto& point : points) {
            int x = point[0];
            int y = point[1];
            int distSquared = x * x + y * y;

            // Push current point with its distance to the max heap
            maxHeap.push({distSquared, point});

            // Ensure heap size does not exceed k
            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        }

        // Collect the k closest points from the max heap
        vector<vector<int>> result;
        while (!maxHeap.empty()) {
            result.push_back(maxHeap.top().second);
            maxHeap.pop();
        }

        return result;
    }
};