class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> minHeap; // Min-heap for the k largest elements
    int k; // The target k value

public:
    // Constructor to initialize the object with k and the initial stream
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int num : nums) {
            add(num); // Add each number to the heap
        }
    }

    // Add a new value to the stream and return the kth largest element
    int add(int val) {
        // Add the new value to the heap
        minHeap.push(val);

        // If the heap size exceeds k, remove the smallest element
        if (minHeap.size() > k) {
            minHeap.pop();
        }

        // The root of the heap is the kth largest element
        return minHeap.top();
    }
};