class Solution {
    bool dfs(vector<vector<char>>& board, int i, int j, string word, int index) {
        if (index == word.length())
            return true;
        if (i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j] != word[index])  
            return false;
        
        char c = board[i][j];
        board[i][j] = '*';
    
        bool ans = dfs(board, i-1, j, word, index+1) || dfs(board, i+1, j, word, index+1) || 
                    dfs(board, i, j-1, word, index+1) || dfs(board, i, j+1, word, index+1);
        board[i][j] = c;
        return ans;   
    }
  public:
    bool isWordExist(vector<vector<char>>& board, string word) {
        // Code here
        for(int i=0; i<board.size(); i++) 
            for(int j=0; j<board[0].size(); j++) 
                if(dfs(board, i, j, word, 0))
                    return true;
        
        return false;
    }
};