class Solution {
  public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> zerosAtEnd(n);
        int res = 0;
        
        for(int i=0; i<n; i++) {
            int zeros = 0;
            for(int j=n-1;j>=0;j--) {
                if(grid[i][j] == 0)
                    zeros++;
                else
                    break;
            }
            zerosAtEnd[i] = zeros;
        }
        
        for(int i=0; i<n; i++) {
            int required = n-i-1;
            
            if(zerosAtEnd[i] >= required) {
                continue;
            }
            
            int row = i+1;
            while(row<n && zerosAtEnd[row]<required)
                row++;
            if(row == n)
                return -1;
            res += (row-i);
            while(row !=i ) {
                zerosAtEnd[row] =  zerosAtEnd[row-1];
                row--;
            }
        }
        return res;
    }
};