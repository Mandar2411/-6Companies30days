int countSubtreesWithSumXUtil(Node *root, int X, int &count) {
    if(root == NULL)
        return 0;
    
    int leftSubtreeSum = countSubtreesWithSumXUtil(root->left, X, count);
    int rightSubtreeSum = countSubtreesWithSumXUtil(root->right, X, count);
    
    int sum = leftSubtreeSum + rightSubtreeSum + root->data;
    
    if(sum == X)
        count++;
        
    return sum;
}

int countSubtreesWithSumX(Node* root, int X) {
    // Code here
    int count = 0;
    countSubtreesWithSumXUtil(root, X, count);
    return count;
}