void rotate(vector<vector<int> >& matrix) {
    // Your code goes here
    int n = matrix.size();
    for(int i=0; i<n; i++)
        reverse(matrix[i].begin(), matrix[i].end());
    
    for(int i=0; i<n; i++) {
        for(int j=i; j<n; j++)
            swap(matrix[i][j], matrix[j][i]);
    }
}