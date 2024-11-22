class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        double totalTax = 0.0; // Initialize total tax
    int prevUpper = 0;     // Tracks the upper limit of the previous bracket

    for (const auto& bracket : brackets) {
        int upper = bracket[0];      // Current bracket's upper limit
        int percent = bracket[1];   // Tax percentage for the current bracket
        
        // Calculate the taxable amount in this bracket
        int taxableIncome = min(income, upper - prevUpper);

        // Calculate tax and add it to the total tax
        totalTax += taxableIncome * (percent / 100.0);

        // Decrease the income by the taxable amount
        income -= taxableIncome;

        // Update the previous upper limit
        prevUpper = upper;

        // Break if no income remains
        if (income <= 0) break;
    }
    return totalTax;
    }
};