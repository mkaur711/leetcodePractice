class Solution {
public:
    // Function to find the median of two sorted arrays
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    // Ensure that nums1 is the smaller array to minimize the binary search space
    if (nums1.size() > nums2.size())
        return findMedianSortedArrays(nums2, nums1);
    
    int m = nums1.size(); // Size of the first array
    int n = nums2.size(); // Size of the second array
    int left = 0, right = m; // Initialize binary search bounds
    
    // Start binary search on the smaller array
    while (left <= right) {
        // Calculate the partition points for nums1 and nums2
        int partitionX = (left + right) / 2;
        int partitionY = (m + n + 1) / 2 - partitionX;

        // Get the max element on the left side of nums1's partition, or INT_MIN if partitionX is 0
        int maxX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
        // Get the min element on the right side of nums1's partition, or INT_MAX if partitionX is at the end
        int minX = (partitionX == m) ? INT_MAX : nums1[partitionX];
        
        // Get the max element on the left side of nums2's partition, or INT_MIN if partitionY is 0
        int maxY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
        // Get the min element on the right side of nums2's partition, or INT_MAX if partitionY is at the end
        int minY = (partitionY == n) ? INT_MAX : nums2[partitionY];

        // Check if we have the correct partition
        if (maxX <= minY && maxY <= minX) {
            // If total length is even, the median is the average of the max of left elements and min of right elements
            if ((m + n) % 2 == 0)
                return (max(maxX, maxY) + min(minX, minY)) / 2.0;
            // If total length is odd, the median is the max of left elements
            else
                return max(maxX, maxY);
        }
        // If maxX is greater than minY, move left in nums1
        else if (maxX > minY) {
            right = partitionX - 1;  // Move towards the left in nums1
        }
        // Otherwise, move right in nums1
        else {
            left = partitionX + 1;   // Move towards the right in nums1
        }
    }
    
    return 0;
}

};