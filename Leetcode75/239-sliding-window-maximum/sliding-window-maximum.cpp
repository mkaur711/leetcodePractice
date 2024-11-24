class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq; // To store indices of elements in the current window
    vector<int> result; // To store the maximums for each window

    for (int i = 0; i < nums.size(); i++) {
        // Remove indices that are out of the current window
        if (!dq.empty() && dq.front() < i - k + 1) {
            dq.pop_front();
        }

        // Remove elements from the back that are smaller than the current element
        while (!dq.empty() && nums[dq.back()] < nums[i]) {
            dq.pop_back();
        }

        // Add the current element's index
        dq.push_back(i);

        // Add the maximum to the result (start adding after the first k elements)
        if (i >= k - 1) {
            result.push_back(nums[dq.front()]);
        }
    }

    return result;     
    }
};