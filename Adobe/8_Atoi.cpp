class Solution {
  public:
    /*You are required to complete this method */
    int atoi(string str) {
        //Your code here
        int ans = 0, i = 0, n = str.length();
        bool isNegative;
        
        if(str[0] == '-') {
            isNegative = true;
            i++;
        } else {
            isNegative = false;
        }
        
        while(i<n) {
            if((str[i]-'0') >= 0 && (str[i]-'0') <= 9)
                ans = ans*10 + (str[i]-'0');
            else
                return -1;
            i++;
        }
        
        if(isNegative)
            return ans*-1;
        else
            return ans;
    }
};