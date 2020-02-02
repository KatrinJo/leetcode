class Solution {
public:
    /**
     * @param maze: the maze
     * @param start: the start
     * @param destination: the destination
     * @return: whether the ball could stop at the destination
     */
    
    int d[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};
    
    void dfs(vector<vector<int>> &maze, vector<vector<bool>> &visted, int x, int y, int m, int n, int dir) {
        int nx = 0, ny = 0, dis = 0;
        for (dis = 1; ; ++dis) {
            nx = x + dis * d[dir][0];
            ny = y + dis * d[dir][1];
            if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                break;
            if (maze[nx][ny])
                break;
        }
        --dis;
        nx = x + dis * d[dir][0];
        ny = y + dis * d[dir][1];
        if (visted[nx][ny])
            return;
        visted[nx][ny] = true;
        int tx, ty;
        for (int k = 0; k < 4; ++k) {
            if ((dir + k) % 2 == 0)
                continue;
            dfs(maze, visted, nx, ny, m, n, k);
        }
    }
    
    bool hasPath(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination) {
        // write your code here
        int m = maze.size();
        if (m == 0)
            return false;
        int n = maze[0].size();
        if (n == 0)
            return false;
            
        vector<vector<bool>> visted(m, vector<bool>(n,false));
        
        int x = start[0], y = start[1];
        int nx, ny;
        visted[x][y] = true;
        for (int dir = 0; dir < 4; ++dir) {
            dfs(maze, visted, x, y, m, n, dir);
        }
        
        return visted[destination[0]][destination[1]];
        
        
    }
};
