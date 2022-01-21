class Solution {
  public:
    int kvowelwords(int N, int K) {
        // Write Your Code here
        long mod = 1e9+7;
        long power[N+1];
        power[0]=1;
        for(int i=1; i<=N; i++) {
            power[i] = power[i-1]*5;
            power[i] %= mod;
        }
        
        vector<vector<long>> dp(N+1, vector<long>(K+1, 0));
        long curr = 1;
        
        for(int i=1; i<=N; i++) {
            dp[i][0] = curr*21; 
            dp[i][0] %= mod;
            curr = dp[i][0]; 
            for(int j=1; j<=K; j++) {             
                if(j == i)
                    dp[i][j] = power[i];
                else if(j > i)
                    dp[i][j] = 0;
                else
                    dp[i][j] = dp[i-1][j-1]*5;
                
                dp[i][j] %= mod;
                curr = (curr + dp[i][j]) % mod;
            }
        }
        return curr;
    }
};