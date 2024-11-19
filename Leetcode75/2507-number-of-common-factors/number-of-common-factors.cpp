class Solution {
public:

        // Function to compute the GCD using the Euclidean algorithm
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    // Function to count common factors of a and b
    int commonFactors(int a, int b) {
        int gcdValue = gcd(a, b); // Step 1: Find the GCD of a and b
        int count = 0; // Step 2: Initialize counter for common factors

        // Step 3: Count all divisors of the GCD
        for (int i = 1; i <= sqrt(gcdValue); ++i) {
            if (gcdValue % i == 0) {
                count++; // i is a factor
                if (i != gcdValue / i) {
                    count++; // The paired factor is also a factor
                }
            }
        }
        return count;
    }
};