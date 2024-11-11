#include <vector>
#include <algorithm>
#include <climits> // for INT_MAX

class Solution {
public:
    int coinChange(std::vector<int>& coins, int amount) {
        // Initialize dp array with a value greater than any possible number of coins (amount + 1).
        int max = amount + 1;
        std::vector<int> dp(amount + 1, max);
        
        // Base case: 0 coins are needed to make amount 0
        dp[0] = 0;
        
        // Loop over all amounts from 1 to amount
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (coins[j] <= i) {
                    // Update dp[i] by checking the minimum coins needed for (i - coins[j]) + 1
                    dp[i] = std::min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        
        // If dp[amount] is still max, return -1, otherwise return dp[amount]
        return dp[amount] > amount ? -1 : dp[amount];
    }
};
