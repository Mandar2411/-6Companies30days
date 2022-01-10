class Solution{
public:
    int isValid(vector<vector<int>> mat) {
        // code here
        unordered_set<int> rows[9], cols[9], box[9];
        
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(mat[i][j] != 0) {
                    int val = mat[i][j];
                    
                    if(rows[i].find(val) != rows[i].end())
                        return 0;
                    rows[i].insert(val);
                    
                    if(cols[j].find(val) != cols[j].end())
                        return 0;
                    cols[j].insert(val);
                    
                    int box_index = (i/3)*3 + j/3;
                    
                    if(box[box_index].find(val) != box[box_index].end())
                        return 0;
                    box[box_index].insert(val);    
                }
            }
        }
        return 1;
    }
};