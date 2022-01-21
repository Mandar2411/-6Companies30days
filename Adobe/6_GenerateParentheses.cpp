class Solution {
    void AllParenthesisUtil(vector<string> &res, string s, int n, int ope, int clo) {
        if(clo == n) {
            res.push_back(s);
            return;
        }

        if(ope > clo) {
            AllParenthesisUtil(res , s + ')', n, ope, clo+1);
        }
        if(ope < n) {
            AllParenthesisUtil(res ,s + '(', n, ope+1, clo);
        }
    }
    public:
    vector<string> AllParenthesis(int n) {
        // Your code goes here 
        vector <string> res;
        int ope = 0, clo = 0;
        AllParenthesisUtil(res, "", n, ope, clo);
    
        return res;
    }
};