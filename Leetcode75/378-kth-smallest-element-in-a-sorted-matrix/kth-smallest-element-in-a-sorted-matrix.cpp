class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
     int n = matrix.size();

    // Min-heap to store (value, row, col)
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> min_heap;

    // Initialize the heap with the first element of each row
    for (int i = 0; i < n; ++i) {
        min_heap.push({matrix[i][0], i, 0});
    }

    // Pop the smallest element from the heap k-1 times
    for (int i = 0; i < k - 1; ++i) {
        auto [val, row, col] = min_heap.top();
        min_heap.pop();

        // If there's a next element in the same row, add it to the heap
        if (col + 1 < n) {
            min_heap.push({matrix[row][col + 1], row, col + 1});
        }
    }

    // The kth smallest element is now at the top of the heap
    return get<0>(min_heap.top());
}
};