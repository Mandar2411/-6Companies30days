class Solution {
    bool isValidCell(int x, int y, int m, int n, vector<vector<int>>& grid) {
        return (x>=0 && x<m && y>=0 && y<n && grid[x][y]==1);
    }
    
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if (grid.empty()) 
            return 0;

        int countFreshOranges = 0;
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q; 

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if (grid[i][j] == 1)
                    countFreshOranges++;
                else if (grid[i][j] == 2)
                    q.push({i, j});
            }
        }

        int time = 0;
        
        while(countFreshOranges != 0 && !q.empty()) {
            int qsize = q.size();
            
            vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

            for(int i=0; i<qsize; i++) {
                int rottenX = q.front().first;
                int rottenY = q.front().second;
                q.pop();

                for(auto d : dirs) {
                    int newX = rottenX + d.first;
                    int newY = rottenY + d.second;
                  
                    if(isValidCell(newX, newY, m, n, grid)) {
                        grid[newX][newY] = 2;
                        countFreshOranges--;
                        q.push({newX, newY});
                    }
                }
            }
            time++;
        }  
        
        if(countFreshOranges == 0)
            return time;
        return -1;
    }
};