class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        // Code here.
        int n = nums.size();
        
        if(n%2)
            return false;
            
        vector<int> count(k, 0);
        
        for(int i=0; i<n; i++) {
            count[nums[i] % k]++;
        }    
        
        if(count[0]%2)
            return false;
        
        for(int i=1; i<k; i++) {
            if(count[i] != count[k-i])
                return false;
        }    
        
        return true;
    }
};