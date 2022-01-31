class Solution {
  public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int, int>> engineers;
        priority_queue<long, vector<long>, greater<long>> pq;
        
        for(int i=0; i<n; i++)
            engineers.push_back({efficiency[i], speed[i]});
        
        sort(engineers.begin(), engineers.end());
        
        long ans = 0, sum = 0, mod = 1e9+7;
        
        for(int i=n-1; i>=0; i--) {
            pq.push(engineers[i].second);
            sum += engineers[i].second;
            
            if(pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }
            ans = max(ans, sum * engineers[i].first);
        }
        
        return (ans % mod);
    }
};