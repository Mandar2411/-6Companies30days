class Solution {
  public:
    bool isPossible(long long mid, vector<int> &piles, int H) {
        int moves = 0;
        for(auto x : piles) {
            moves += (x/mid);
            if(x%mid != 0)
                moves++;
        }
        return moves<=H;
    }
    
    int minEatingSpeed(vector<int>& piles, int H) {
        int n = piles.size();
        long long l, h, ans;
        l = 1, h = 1e9;
        
        while(l<h) {
            long long mid = l + (h-l)/2;
            if(isPossible(mid, piles, H)) {
                h = mid;
            } else {
                l = mid +1;
            }
        }
        return h;
    }
};