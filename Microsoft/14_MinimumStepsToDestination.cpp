class Solution {
  public:
    int minSteps(int D) {
        // code here
        int i = 0, currSum = 0;
        
        while(true) {
            currSum += i;
            
            if(currSum == D)
                return i;
            if(currSum > D)
                break;
            i++;
        }
        
        int diff = currSum - D;
        
        if(diff % 2 == 0)
            return i;
        
        if(i%2)
            return i+2;
        else
            return i+1;
    }
};