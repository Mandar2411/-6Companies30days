class Solution {
  public:
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n) {
        // Your code here
        if(n == 1)
            return arr[0];
        if(n == 2)
            return max(arr[0], arr[1]);
        
        int maxLoot[n];
        maxLoot[0] = arr[0];
        maxLoot[1] = max(arr[0], arr[1]);
        
        for(int i=2; i<n; i++) {
            maxLoot[i] = max(maxLoot[i-1], maxLoot[i-2] + arr[i]);
        }
        
        return maxLoot[n-1];
    }
};