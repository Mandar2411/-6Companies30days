class Solution {
     void findMaximumNumUtil(string str, string &res, int k, int index) {
        if(k == 0)
            return;
        
        int n = str.length();
        char maxChar = str[index];
        for(int i = index+1; i<n; i++) {
            if(maxChar < str[i])
                maxChar = str[i];
        }
        if(maxChar != str[index])
            k--;
            
        for(int i = n-1; i>=index; i--) {
            if(str[i] == maxChar) {
                swap(str[index], str[i]);
                res = max(res, str);
                findMaximumNumUtil(str, res, k, index+1);
                swap(str[index], str[i]);
            }
        }
    }
    
  public:
    //Function to find the largest number after k swaps.
    string findMaximumNum(string str, int k) {
       // code here.
       string res = str;
       int n = str.length();
       findMaximumNumUtil(str, res, k, 0);
       return res;
    }
};
