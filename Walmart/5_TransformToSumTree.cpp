class Solution {
    int convert(Node *node) {
        if(node == NULL)
            return 0;
        int leftSum = convert(node->left);
        int rightSum = convert(node->right);
        
        int sum = node->data + leftSum + rightSum;
        node->data = leftSum + rightSum;
        return sum;
    }
  public:
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    void toSumTree(Node *node) {
        // Your code here
        convert(node);
    }
};