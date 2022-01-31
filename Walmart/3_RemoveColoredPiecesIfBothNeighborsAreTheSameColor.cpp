class Solution {
  public:
    bool winnerOfGame(string s) {
        int n = s.length();
        
        int a=0, b=0;
        
        for(int i=1;i<n-1;i++)
        {
            if(s[i-1]=='A' && s[i]=='A' && s[i+1]=='A')
                a++;
           if(s[i-1]=='B' && s[i]=='B' && s[i+1]=='B')
                b++; 
        }
        
        if(a<=b)
            return false;
        
        return true;
    }
};