class Solution {
public:
    int minArrayLength(vector<int>& nums, int k) {
         std::stack<long long> s; // Use long long stack to avoid overflow

    for (int num : nums) {
        long long current = num; // Cast num to long long to handle large products
        // While the stack is non-empty and the top element can merge with current
        while (!s.empty() && s.top() * current <= k) {
            current *= s.top();  // Merge top element with current (using long long)
            s.pop();             // Remove the top element after merging
        }
        s.push(current);  // Push the resulting merged element (or original element) to the stack
    }

    // The size of the stack is the reduced length of the array
    return s.size();
    }
};