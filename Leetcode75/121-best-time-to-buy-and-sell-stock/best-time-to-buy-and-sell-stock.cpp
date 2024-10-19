class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;  // Handle edge case for less than 2 prices

        int buy = 0;  // Initialize buy pointer
        int sell = 1; // Initialize sell pointer
        int maxProfit = 0;  // Initialize maxProfit

        // Iterate through the prices using the two pointers
        while (sell < prices.size()) {
            // If current sell price is greater than buy price, calculate profit
            if (prices[sell] > prices[buy]) {
                int profit = prices[sell] - prices[buy];
                maxProfit = std::max(maxProfit, profit);  // Update maxProfit
            } else {
                buy = sell;  // Update buy pointer to current sell pointer
            }
            sell++;  // Move the sell pointer forward
        }

        return maxProfit;  // Return the maximum profit found
    }
};