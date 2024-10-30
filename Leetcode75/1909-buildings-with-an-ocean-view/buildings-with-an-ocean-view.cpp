class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        vector<int> result; // To store indices of buildings with ocean view
        int maxHeight = 0;  // Track the max height seen to the right
        
        // Traverse from right to left
        for (int i = heights.size() - 1; i >= 0; i--) {
            if (heights[i] > maxHeight) { // Check if current building is taller than maxHeight
                result.push_back(i); // Add index to result if it has an ocean view
                maxHeight = heights[i]; // Update maxHeight
            }
        }
        
        // Reverse the result so indices are in increasing order
        reverse(result.begin(), result.end());
        return result;
    }
};