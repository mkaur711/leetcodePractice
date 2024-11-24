class Solution {
public:
    // Function to calculate the minimal total travel distance
int minTotalDistance(vector<vector<int>>& grid) {
    vector<int> rows, cols;
    int m = grid.size(), n = grid[0].size();

    // Collect all row indices of '1's
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == 1) rows.push_back(i);
        }
    }

    // Collect all column indices of '1's
    for (int j = 0; j < n; ++j) {
        for (int i = 0; i < m; ++i) {
            if (grid[i][j] == 1) cols.push_back(j);
        }
    }

    // Function to calculate total distance for a sorted array
    auto minDistance = [](vector<int>& points) {
        int distance = 0;
        int l = 0, r = points.size() - 1;
        while (l < r) {
            distance += points[r--] - points[l++];
        }
        return distance;
    };

    return minDistance(rows) + minDistance(cols);
}

};