class GameEndException : public exception {
public:
    GameEndException () { }
};
class AlreadyTakenException : public exception {
public:
    AlreadyTakenException () { }
};
class TicTacToe {
public:
    int grid[3][3];
    int curr;
    bool gameEnd;
   
    /** Initialize your data structure here. */
    TicTacToe() {
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                grid[i][j] = 0;
        curr = 1;
        gameEnd = false;
    }
    void initialize() {
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                grid[i][j] = 0;
        curr = 1;
        gameEnd = false;
    }
    bool isBoardFull()
	{
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				if (grid[i][j] == 0)
					return false;
		gameEnd = true;
		return true;
	}
    
    bool move(int row, int col) {
        if (gameEnd) {
            GameEndException a;
            throw a;
        }
        
        
        if (grid[row][col] != 0) {
            AlreadyTakenException a;
            throw a;
        }
        
        grid[row][col] = curr;

        if ((grid[0][col]+grid[1][col]+grid[2][col] == curr * 3) ||
            (grid[row][0]+grid[row][1]+grid[row][2] == curr * 3) ||
            (grid[0][0]+grid[1][1]+grid[2][2] == curr * 3) || 
            (grid[2][0]+grid[1][1]+grid[0][2] == curr * 3)) {
            
            gameEnd = true;
            return true;
        }
        
        curr *= -1;
        return false;
    }
};