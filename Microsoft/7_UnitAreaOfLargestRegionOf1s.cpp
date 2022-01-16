class Solution {
    int row[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int col[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    
    bool isValid(int row, int col, int n, int m, vector<vector<bool>> &visited, vector<vector<int>> &grid) {
        return (row>=0 && row<n && col>=0 && col<m && grid[row][col] && !visited[row][col]);
    }
    
    void DFS(vector<vector<int>>& grid, int i, int j, vector<vector<bool>> &visited, int &count) {
        int n = grid.size(), m = grid[0].size();
        visited[i][j] = true;
        
        for(int k=0; k<8; k++) {
            int nextRow = i + row[k];
            int nextCol = j + col[k];
            
            if(isValid(nextRow, nextCol, n, m, visited, grid)) {
                count++;
                DFS(grid, nextRow, nextCol, visited, count);
            }
        }
    }
    
    public:
    //Function to find unit area of the largest region of 1s.
    int findMaxArea(vector<vector<int>>& grid) {
        // Code here
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        
        int res = INT_MIN;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] && !visited[i][j]) {
                    
                    int count = 1;
                    DFS(grid, i, j, visited, count);
                    res = max(res, count);
                }
            }
        }
        return res;
    }
};