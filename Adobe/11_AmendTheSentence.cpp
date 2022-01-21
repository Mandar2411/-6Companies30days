class Solution {
    public:
    string amendSentence(string s) {
        // your code here
        string res;
        int n = s.length();
        
        res += tolower(s[0]);
        int i = 1;
        while(i<n) {
            if(s[i]>='A' && s[i]<='Z') {
                res += ' ';
                res += tolower(s[i]);
            } else {
                res += s[i];
            }
            i++;
        }
        return res;
    }
};