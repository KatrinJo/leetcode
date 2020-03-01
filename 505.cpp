// 在lintcode做的……

class Solution {
public:
    /**
     * @param maze: the maze
     * @param start: the start
     * @param destination: the destination
     * @return: whether the ball could stop at the destination
     */
    
    int shortestDistance(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination) {
        // write your code here
        int m = maze.size();
        if (m == 0)
            return false;
        int n = maze[0].size();
        if (n == 0)
            return false;
            
        vector<vector<int>> visted(m, vector<int>(n,false));
        vector<vector<int>> step(m, vector<int>(n,-1));
        vector<vector<int>> myque;
        int d[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};
        
        int st = 0, se = 4, dis, k;
        int nx, ny;
        vector<int> tmp = start;
        tmp.push_back(0);
        for (int i = 0; i < 4; ++i) {
            tmp[2] = i;
            myque.push_back(tmp);
        }
        step[start[0]][start[1]] = 0;
        
        while(st < se) {
            auto & p = myque[st];
            ++st;
            k = p[2];
            
            if ((visted[p[0]][p[1]] >> k) & 1)
                continue;
            visted[p[0]][p[1]] |= 1 << k;
            
            
            for (dis = 1;; ++dis) {
                nx = p[0] + dis * d[k][0];
                ny = p[1] + dis * d[k][1];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                    break;
                if (maze[nx][ny])
                    break;
            }
            if (dis == 1) {
                continue;
            }
            --dis;
            nx -= d[k][0];
            ny -= d[k][1];
            
            if (step[nx][ny] == -1)
                step[nx][ny] = step[p[0]][p[1]] + dis;
            else
                step[nx][ny] = min(step[nx][ny], step[p[0]][p[1]] + dis);
            
            if (!((visted[nx][ny] >> ((k + 1) % 4)) & 1)) {
                myque.push_back(vector<int>{nx, ny, (k + 1) % 4});
                ++se;
            }
            if (!((visted[nx][ny] >> ((k + 3) % 4)) & 1)) {
                myque.push_back(vector<int>{nx, ny, (k + 3) % 4});
                ++se;
            }
            visted[nx][ny] |= 1 << k;
            visted[nx][ny] |= 1 << ((2 + k) % 4);
        }
        return step[destination[0]][destination[1]];
    }
};