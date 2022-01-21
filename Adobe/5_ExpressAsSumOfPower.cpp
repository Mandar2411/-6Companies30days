class Solution {
    public:
    long long numOfWays(int n, int x) {
        // code here
        vector<long long> dp(n+1, 0);
        
        dp[0] = 1;
        
        long long mx = pow(n, 1.0/x);
        
        for(long long i=1; i<=mx; i++) {
            long long ipowx = pow(i, x);
            for(long long j=n; j>=ipowx; j--) {
                dp[j] += dp[j-ipowx]; 
            }
        }
        
        return dp[n];
    }
};