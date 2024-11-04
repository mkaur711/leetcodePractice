class Solution {
public:
    string addStrings(string num1, string num2) {
     int i = num1.size() - 1; // Pointer for num1 starting from last index
    int j = num2.size() - 1; // Pointer for num2 starting from last index
    int carry = 0; // Variable to store carry
    string result; // Resultant string

    // Loop while there are digits left in either number or there's a carry
    while (i >= 0 || j >= 0 || carry) {
        int digit1 = (i >= 0) ? num1[i] - '0' : 0; // Current digit of num1 or 0 if out of bounds
        int digit2 = (j >= 0) ? num2[j] - '0' : 0; // Current digit of num2 or 0 if out of bounds

        int sum = digit1 + digit2 + carry; // Sum of current digits and carry
        carry = sum / 10; // Update carry for the next iteration
        result.push_back((sum % 10) + '0'); // Append last digit of sum to result

        i--; // Move to the next digit in num1
        j--; // Move to the next digit in num2
    }

    reverse(result.begin(), result.end()); // Reverse the result since we built it from least significant to most significant digit
    return result;
}
};