class Solution {
    void possibleWordsUtil(int a[], int n, vector<string> &possibleWords, int i,unordered_map<int,string> m, string curr) {
        if(i==n) {
            possibleWords.push_back(curr);
            return;
        }
        
        string s = m[a[i]];
        
        int slen = s.length();
    
        for(int j=0;j<slen;j++) {
            curr.push_back(s[j]);
            possibleWordsUtil(a, n, possibleWords, i+1, m, curr);
            curr.pop_back();
        }
    }
    
    
    public:
    //Function to find list of all words possible by pressing given numbers.
    vector<string> possibleWords(int a[], int N) {
        //Your code here
        vector<string> possibleWords;
        
        unordered_map<int,string> m;
    
        m.insert(make_pair(2, "abc"));
        m.insert(make_pair(3, "def"));
        m.insert(make_pair(4, "ghi"));
        m.insert(make_pair(5, "jkl"));
        m.insert(make_pair(6, "mno"));
        m.insert(make_pair(7, "pqrs"));
        m.insert(make_pair(8, "tuv"));
        m.insert(make_pair(9, "wxyz"));
    
        
        possibleWordsUtil(a, N, possibleWords, 0, m, "");
        
        return possibleWords;
    }
};