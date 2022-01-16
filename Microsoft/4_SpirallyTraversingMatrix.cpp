class Solution {
  public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) {
        // code here 
        vector<int> spiralTraverse;
        int minr = 0, minc = 0, maxr = r-1, maxc = c-1;
        int tn = (matrix.size()*matrix[0].size()), count = 0;
        
        while (count < tn) {    
            // top view
            for (int j=minc, i=minr; j<=maxc && count<tn; j++) {
                spiralTraverse.push_back(matrix[i][j]);
                count++;
            }
            minr++;
            // right view
            for (int i=minr, j=maxc; i<=maxr && count<tn; i++) {
                spiralTraverse.push_back(matrix[i][j]);
                count++;
            }
            maxc--;
            //bottom view
            for (int j=maxc, i=maxr; j>=minc && count<tn; j--) {
                spiralTraverse.push_back(matrix[i][j]);
                count++;
            }
            maxr--;
            // left view
            for (int i=maxr, j=minc; i>=minr && count<tn; i--) {
                spiralTraverse.push_back(matrix[i][j]);
                count++;
            }
            minc++;
        }
        return spiralTraverse;
    }
};