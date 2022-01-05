class Solution {
  public:
    long long squaresInChessBoard(long long N) {
        // code here
        // Answer = N^2 + (N-1)^2 + (N-2)^2 + ........ + 1
        return N * (N + 1) * (2*N + 1) / 6;
    }
};