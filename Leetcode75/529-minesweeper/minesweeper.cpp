class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        
        // If the clicked cell contains a mine ('M'), change it to 'X' (game over)
        if(board[click[0]][click[1]] == 'M') {
            board[click[0]][click[1]] = 'X';
            return board; // Return the updated board with the mine revealed
        }
        
        // If the clicked cell is already a blank ('B'), no action is needed
        else if(board[click[0]][click[1]] == 'B') {
            return board; // Return the board as is
        }
        
        // Initialize variables to count adjacent mines and get board dimensions
        int totalmine = 0;
        int i = click[0], j = click[1];
        int m = board.size(), n = board[0].size();

        // Direction vectors to check all 8 neighboring cells
        vector<int> row = {-1, -1, -1, 0, 0, 1, 1, 1};
        vector<int> col = {-1, 0, 1, -1, 1, -1, 0, 1};
        
        // Loop through all neighbors of the clicked cell to count mines
        for(int k = 0; k < 8; k++) {
            int irow = i + row[k], jcol = j + col[k];
            // Check if neighbor is within bounds and contains a mine
            if(irow >= 0 && jcol >= 0 && irow < m && jcol < n) {
                if(board[irow][jcol] == 'M') totalmine++;
            }
        }
        
        // If there are adjacent mines, display the count in the clicked cell
        if(totalmine > 0) {
            board[i][j] = char(totalmine + '0'); // Convert mine count to a character
            return board; // Return the updated board
        }
        
        // If there are no adjacent mines, reveal the cell as blank ('B')
        else {
            board[i][j] = 'B';
            
            // Recursively reveal all adjacent cells that are within bounds
            for(int k = 0; k < 8; k++) {
                int irow = i + row[k], jcol = j + col[k];
                if(irow >= 0 && jcol >= 0 && irow < m && jcol < n) {
                    vector<int> v = {irow, jcol}; // Set coordinates for recursive call
                    updateBoard(board, v); // Recursively update the neighboring cell
                }
            }
        }
        
        // Return the updated board after processing the click
        return board;
    }
};
