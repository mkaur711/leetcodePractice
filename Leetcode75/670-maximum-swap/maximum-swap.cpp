class Solution {
public:
    int maximumSwap(int num) {
        // Convert the number to a string of digits
    string digits = to_string(num);
    int n = digits.size();
    
    // Vector to store the index of the largest digit to the right of each position
    vector<int> maxIdx(n);
    maxIdx[n - 1] = n - 1; // The last digit is its own max to the right
    
    // Traverse from the second-last digit to the beginning to find the max index at each position
    for (int i = n - 2; i >= 0; --i) {
        if (digits[i] > digits[maxIdx[i + 1]]) {
            maxIdx[i] = i;
        } else {
            maxIdx[i] = maxIdx[i + 1];
        }
    }
    
    // Find the first position where a swap would increase the number
    for (int i = 0; i < n; ++i) {
        // If there is a larger digit to the right, perform the swap
        if (digits[i] != digits[maxIdx[i]]) {
            swap(digits[i], digits[maxIdx[i]]);
            break; // Only one swap allowed
        }
    }
    
    // Convert the modified string of digits back to an integer
    return stoi(digits);
    }
};