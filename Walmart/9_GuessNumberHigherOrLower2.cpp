class Solution {
    int recGetMoneyAmount(vector<vector<int>> &dp, int start, int end) {
        if(start >= end) 
            return 0;
        
        if(dp[start][end] != 0) 
            return dp[start][end];
        int res = INT_MAX;
        
        for(int i=start; i<=end; i++) {
            int curr = i + max(recGetMoneyAmount(dp, start, i-1), recGetMoneyAmount(dp, i+1, end));
            res = min(res, curr);
        }
        
        dp[start][end] = res;
        return res;
    }
  public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+1, vector<int>(n+1,0));
        return recGetMoneyAmount(dp, 1, n);
    }
};