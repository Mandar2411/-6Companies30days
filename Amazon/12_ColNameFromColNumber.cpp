class Solution{
    public:
    string colName (long long int n) {
        string res="";
        while(n>0) {
            int current = n%26;
            
            if(current == 0) {
                res = 'Z' + res;
                n = n/26 - 1;
            } else {
                char character = current - 1 + 'A';
                res = character + res;
                n = n/26;
            }
        }
        
        return res;
        // your code here
    }
};