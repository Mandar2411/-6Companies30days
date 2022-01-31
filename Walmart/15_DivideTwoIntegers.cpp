class Solution {
  public:
    int divide(int dividend, int divisor) {
        
        if(dividend == 1<<31 && divisor == -1) 
            return INT_MAX;
        if(dividend == -2147483648 && divisor == 1)
            return INT_MIN;
        
        bool isNegative = false;
        
        if(dividend == 0)
            return 0;
        
        if((dividend>0 && divisor<0) || (dividend<0 && divisor>0))
            isNegative = true;
        
        long myDividend = dividend;
        long myDivisor = divisor;
        
        if(myDividend<0)
            myDividend = -1 * myDividend;
        if(myDivisor < 0)
            myDivisor = -1 * myDivisor;
        
        int res = 0;
        while(myDividend >= myDivisor) {
            int count = 0;
            
            while(myDividend >= (myDivisor << 1 << count)){
                count++;
            }
            res += 1 << count;
            myDividend -= myDivisor << count ;
        }
        
        return isNegative ? -1*res : res;
    }
};