class Solution {
    long long powerUtil(int N, int R) {
        if(R == 0)
            return 1;
        long long tmp = powerUtil(N, R/2);
        tmp = (tmp * tmp) % mod;
        
        if(R % 2 == 0)
            return tmp;
        else
            return (tmp * N) % mod;
    }
  public:
    //You need to complete this fucntion
    long long power(int N,int R) {
        //Your code here
        return powerUtil(N, R);
    }
};