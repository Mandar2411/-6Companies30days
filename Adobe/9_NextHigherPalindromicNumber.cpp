class Solution {
  public:
    string nextPalin(string N) { 
        //complete the function here
        int n = N.length();
        if(n <= 3) 
            return "-1";
            
        int mid = n/2;
        
        string firstHalf = N.substr(0, mid);
        string tmp = firstHalf;
        
        next_permutation(firstHalf.begin(),firstHalf.end());
        
        if(firstHalf <= tmp) 
            return "-1"; 
            
        string res = firstHalf;
        if(n%2 == 1) 
            res += N[mid];
        
        reverse(firstHalf.begin(), firstHalf.end());
        res += firstHalf;
        
        return res;
    }
};