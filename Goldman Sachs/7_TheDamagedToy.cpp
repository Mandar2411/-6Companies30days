class Solution {
  public:
    int findPosition(int N , int M , int K) {
        // code here
        if(M <= N - K + 1)
            return M + K - 1;
        
        M = M - (N - K + 1);
        
        if(M % N == 0)
            return N;
        else 
            return (M % N);
    }
};