class Solution {
  public:
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int total = 0;
        for(int i=0; i<n; i++)
            total += arr[i];
  
        bool dp[n+1][total+1];

        for(int i=1; i<=total; i++)
            dp[0][i] = false;
            
        for(int i=0; i<=n; i++)
            dp[i][0] = true;
    
        for(int i=1; i<=n; i++) {
            for (int j=1; j<=total; j++) {
                dp[i][j] = dp[i-1][j];

                if(arr[i-1] <= j)
                    dp[i][j] = dp[i][j] | dp[i-1][j-arr[i-1]];
            }
        }

        int minDiff = INT_MAX;
   
        for(int j=total/2; j>=0; j--) {
            if(dp[n][j] == true) {
                minDiff = total-2*j;
                break;
            }
        }
        return minDiff;
	} 
};