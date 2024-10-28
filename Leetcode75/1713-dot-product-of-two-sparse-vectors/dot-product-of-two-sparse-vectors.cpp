class SparseVector {
public:
    
    // List of pairs to store non-zero elements as (index, value)
    vector<pair<int, int>> elements;
    
    // Constructor to initialize the sparse vector
    SparseVector(const vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) {
                elements.emplace_back(i, nums[i]);
            }
        }
    }
    
    // Function to compute the dot product with another SparseVector
    int dotProduct(SparseVector& vec) {
        int result = 0;
        int i = 0, j = 0;
        
        // Use two pointers to iterate through both lists of (index, value) pairs
        while (i < elements.size() && j < vec.elements.size()) {
            auto [index1, value1] = elements[i];
            auto [index2, value2] = vec.elements[j];
            
            if (index1 == index2) {
                result += value1 * value2;
                ++i;
                ++j;
            } else if (index1 < index2) {
                ++i;
            } else {
                ++j;
            }
        }
        
        return result;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);