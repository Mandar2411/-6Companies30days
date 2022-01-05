class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minSubarrayLen = INT_MAX;
        
        int begin=0, end=0;
        long long curr_sum=0;
        
        while(end < nums.size()) {
            if(curr_sum + nums[end] >= target) {
                minSubarrayLen = min(minSubarrayLen, end - begin + 1);
                curr_sum -= nums[begin];
                begin++;
                
            } else {
                curr_sum += nums[end];
                end++;
            }
        }
        
        return (minSubarrayLen == INT_MAX) ? 0 : minSubarrayLen;
    }
};