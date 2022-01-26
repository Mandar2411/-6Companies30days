class Solution {
    int dirX[4] = {0, 0, 1, -1};
    int dirY[4] = {1, -1, 0, 0};
    
    bool isValid(int x, int y, int n, vector<vector<int>>& grid) {
        return (x>=0 && y>=0 && x<n && y<n && grid[x][y]==0);
    }
  public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, int>> bfs;
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 1) {
                    bfs.push({i, j});
                }        
            }
        }
        if(bfs.size() == n*n)
            return -1;
        int res = 0;
        while(!bfs.empty()) {
            int qsize = bfs.size();
            while(qsize--) {
                int x = bfs.front().first;
                int y = bfs.front().second;
                bfs.pop();
                
                for(int i=0; i<4; i++) {
                    int newX = x+dirX[i];
                    int newY = y+dirY[i];
                    
                    if(isValid(newX, newY, n, grid)) {
                        grid[newX][newY] = 1;
                        bfs.push({newX, newY});
                    }
                }
            }
            res++;
        }
        return res-1;
    }
};