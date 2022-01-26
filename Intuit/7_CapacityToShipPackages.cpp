class Solution {
    bool isPossible(vector<int>& weights, int mxWeight, int mxDays) {
        int days = 0, curr_weight = 0, i = 0, n = weights.size();
        
        while(i < n) {
            if(curr_weight + weights[i] > mxWeight) {
                curr_weight = 0;
                days++;
            } else {
                curr_weight += weights[i];
                i++;
            }
        }
        days++;
        return (days <= mxDays);
    }
  public:
    int shipWithinDays(vector<int>& weights, int days) {
        int sum = 0, mx = INT_MIN;
        for(auto x: weights) {
            sum += x;
            mx = max(mx, x);
        }
        
        int low = mx, high = sum;
        int ans = sum;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            //cout<<low<<" "<<high<<" "<<mid<<endl;
            if(isPossible(weights, mid, days)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};