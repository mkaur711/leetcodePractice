class Solution {
public:
    // Function to count the number of set bits (1s) in a number
    int countSetBits(int number) {
        int count = 0;
        while (number != 0) {
            count += (number & 1);
            number = number >> 1;
        }
        return count;
    }

    // Function to set the least significant unset bits in 'number' 
    int addSetBits(int number, int bitsToAdd) {
        int bitPosition = 0;
        while (bitsToAdd > 0) {
            while ((number >> bitPosition) & 1 == 1) bitPosition++;
            number = number | (1 << bitPosition);
            bitsToAdd--;
        }
        return number;
    }

    // Function to remove the least significant set bits in 'number'
    int removeSetBits(int number, int bitsToRemove) {
        while (bitsToRemove > 0) {
            number = number & (number - 1);
            bitsToRemove--;
        }
        return number;
    }

    int minimizeXor(int num1, int num2) {
        int setBitsNum1 = countSetBits(num1);
        int setBitsNum2 = countSetBits(num2);

        // If num1 already has the same number of set bits as num2
        if (setBitsNum1 == setBitsNum2) return num1;

        // If num1 has fewer set bits than num2, add the necessary set bits
        if (setBitsNum1 < setBitsNum2) return addSetBits(num1, setBitsNum2 - setBitsNum1);

        // If num1 has more set bits than num2, remove the extra set bits
        return removeSetBits(num1, setBitsNum1 - setBitsNum2);
    }
};