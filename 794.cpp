class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        int numX = 0, numO = 0;
        for (auto & s : board) {
            for (auto c : s) {
                numX += (c == 'X');
                numO += (c == 'O');
            }
        }
        if (numX < numO || numX >= numO + 2)
            return false;
        bool win[2] = {false};
        for (int i = 0; i < 3; ++i)
            if (board[i][0] == board[i][1] && board[i][2] == board[i][1] && board[i][0] != ' ') 
                win[board[i][0] == 'X'] = true;
        for (int j = 0; j < 3; ++j) 
            if (board[0][j] == board[1][j] && board[2][j] == board[1][j] && board[0][j] != ' ')
                win[board[0][j] == 'X'] = true;
        if (board[0][0] == board[1][1] && board[2][2] == board[1][1] && board[1][1] != ' ')
            win[board[0][0] == 'X'] = true;
        if (board[2][0] == board[1][1] && board[0][2] == board[1][1] && board[1][1] != ' ')
            win[board[2][0] == 'X'] = true;
        if ((win[1] && numO == numX) || (win[0] && numO + 1 == numX))
            return false;
        if (win[0] && win[1])
            return false;
        return true;        
    }
};