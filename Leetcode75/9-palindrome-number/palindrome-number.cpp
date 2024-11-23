class Solution {
public:
    bool isPalindrome(int x) {
        // Negative numbers and multiples of 10 (except 0) are not palindromes
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int reversedHalf = 0;
        while (x > reversedHalf) {
            reversedHalf = reversedHalf * 10 + x % 10;  // Reverse the last digit
            x /= 10;  // Remove the last digit from x
        }

        // When x is equal to reversedHalf, the number is a palindrome
        // For odd-length numbers, reversedHalf > x will remove the middle digit
        return x == reversedHalf || x == reversedHalf / 10;
    }
};