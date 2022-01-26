class Solution {
    bool isPossible(vector<int>& nums, int m, int mxSum){
        int noOfSubarrays = 0;
        int curr_sum = 0, n = nums.size();
 
        for(int i = 0; i < n; i++) {
            
            if(curr_sum + nums[i] > mxSum) {
                noOfSubarrays++;
                curr_sum = nums[i];
            } else {
                curr_sum += nums[i];
            }
        }
        noOfSubarrays++;
        
        return (noOfSubarrays <= m);
    }
  public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
    
        int mx = INT_MIN, sum = 0;
        for(int i=0; i<n; i++) {
            sum += nums[i];
            mx = max(mx, nums[i]);
        }
    
        int low = mx, high = sum;
        int ans = sum;
    
        while(low <= high) {
            int mid = low + (high - low) / 2;
            
            if(isPossible(nums, m, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};