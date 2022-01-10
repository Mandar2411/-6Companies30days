class Solution{
    void getParenthesis(int i, int j, string &res, vector<vector<int>> &bracket, char &letter) {
        if (i == j) {
            res += letter;
            letter++;
            return;
        }
        int n = bracket.size();
        
        res += '(';

        getParenthesis(i, bracket[i][j], res, bracket, letter);

        getParenthesis(bracket[i][j] + 1, j, res, bracket, letter);
        
        res += ')';
    }
public:
    string matrixChainOrder(int p[], int n) {
        
        vector<vector<int>> m(n, vector<int>(n));
        vector<vector<int>> bracket(n, vector<int>(n));
        
        for(int i=1; i<n; i++)
            m[i][i] = 0;

        for(int L=2; L<n; L++) {
            for(int i=1; i<n-L+1; i++) {
                int j = i+L-1;
                m[i][j] = INT_MAX;
                
                for(int k=i; k<=j-1; k++) {
                
                    int q = m[i][k] + m[k+1][j] + p[i-1] * p[k] * p[j];
                    if (q < m[i][j]) {
                        m[i][j] = q;
                        bracket[i][j] = k;
                    }
                }
            }
        }
        string res = "";
        char letter = 'A';
        getParenthesis(1, n - 1, res, bracket, letter);
        return res;
    }
};