class Solution {
public:
    double myPow(double x, int n) {
        // Handle negative exponent by taking the reciprocal
        long long power = n;
        if (power < 0) {
            x = 1 / x;
            power = -power;
        }

        double result = 1.0;
        while (power > 0) {
            // If power is odd, multiply result by x
            if (power % 2 == 1) {
                result *= x;
            }
            // Square x and halve the power
            x *= x;
            power /= 2;
        }

        return result;
    }
};