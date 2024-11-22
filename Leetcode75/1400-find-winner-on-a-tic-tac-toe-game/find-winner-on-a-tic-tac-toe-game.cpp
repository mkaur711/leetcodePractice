class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        // Arrays to track rows, columns, and diagonals for both players
    int rows[3] = {0}, cols[3] = {0}, diag = 0, antiDiag = 0;
    bool isA = true; // A starts first

    for (auto& move : moves) {
        int row = move[0], col = move[1];
        int delta = isA ? 1 : -1; // +1 for A, -1 for B

        // Update row, column, and diagonals
        rows[row] += delta;
        cols[col] += delta;
        if (row == col) diag += delta; // Main diagonal
        if (row + col == 2) antiDiag += delta; // Anti-diagonal

        // Check for a winner
        if (abs(rows[row]) == 3 || abs(cols[col]) == 3 || abs(diag) == 3 || abs(antiDiag) == 3) {
            return isA ? "A" : "B"; // Return winner
        }

        isA = !isA; // Alternate turns
    }

    // Check game state
    return moves.size() == 9 ? "Draw" : "Pending";
    }
};