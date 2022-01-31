class Solution {
  public:
    //Function to find total number of unique paths.
    int NumberOfPath(int a, int b) {
        //code here
        vector<vector<int>> paths(a, vector<int>(b, 1));
        for(int i=1; i<a; i++) {
            for(int j=1; j<b; j++) {
                paths[i][j] = paths[i-1][j] + paths[i][j-1];
            }
        }
        return paths[a-1][b-1];
    }
};