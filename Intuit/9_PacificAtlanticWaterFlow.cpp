class Solution {
    int dirX[4] = {0, 0, 1, -1};
    int dirY[4] = {1, -1, 0, 0};
    
    void dfs(vector<vector<int>> &heights, int i, int j, int prev, vector<vector<bool>> &ocean) {
        int rows = heights.size(), cols = heights[0].size();
        if(i<0 || j<0 || i>=rows || j>=cols)
            return;
        if(heights[i][j]<prev || ocean[i][j])
            return;
        
        ocean[i][j] = true;
        for(int k=0; k<4; k++) {
            dfs(heights, i+dirX[k], j+dirY[k], heights[i][j], ocean);
        }
    }
    
  public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> res;
        int rows = heights.size(), cols = heights[0].size();
        
        vector<vector<bool>> pacific(rows, vector<bool>(cols, false));
        vector<vector<bool>> atlantic(rows, vector<bool>(cols, false));
        
        for(int i=0; i<rows; i++) {
            dfs(heights, i, 0, INT_MIN, pacific);
            dfs(heights, i, cols-1, INT_MIN, atlantic);
        }
        for(int i=0; i<cols; i++) {
            dfs(heights, 0, i, INT_MIN, pacific);
            dfs(heights, rows-1, i, INT_MIN, atlantic);
        }
        
        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                if(pacific[i][j] && atlantic[i][j]) {
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }
};