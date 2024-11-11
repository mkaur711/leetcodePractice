class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0;
        int right = arr.size() - k;

        // Binary search to find the closest starting point
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            // Compare distances to decide whether to move left or right
            if (x - arr[mid] > arr[mid + k] - x) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        // Return the k closest elements starting from left index
        return vector<int>(arr.begin() + left, arr.begin() + left + k);
    }
};