class Solution {
public:
    int maxCoins(vector<int>&A, int n) {
	    //Write your code here
	    vector<vector<int>> dp(n, vector<int>(n, 0));
        
	    for(int i=0; i<n; i++) {
		    dp[i][i] = A[i];
	    }

	    for(int gap=0; gap<n; gap++) {
		    for(int i=0, j=gap; j<n; i++, j++) {
			    
			    int x = (i+2 <= j) ? dp[i+2][j] : 0;
                int y = (i+1 <= j-1) ? dp[i+1][j-1] : 0;
                int z = (i <= j-2) ? dp[i][j-2] : 0;
                dp[i][j] = max(A[i] + min(x, y), A[j] + min(y, z));
		    }
	    }
	    
	    return dp[0][n-1];
    }
};