class Solution {
    int mnTime = 0, p = 0, targetDisFromRoot = 0;
    bool gotNode = false;
    
    int height(Node* root) {
        
        if(root == NULL)
            return 0;

        return 1 + max(height(root->left), height(root->right));
    }
    
    void minTimeUtil(Node* root, int target, int disFromRoot) {
        
        if(root == NULL)
            return;

        
        if(root->data == target) {
            gotNode = true;
            mnTime = height(root)-1;
            targetDisFromRoot = disFromRoot;
            return;
        }
        
        minTimeUtil(root->left, target, disFromRoot+1);
        
        if(gotNode) {
            int h = height(root->right);
            mnTime = max(mnTime, h + targetDisFromRoot - disFromRoot);
            return;
        }
        
        minTimeUtil(root->right, target, disFromRoot+1);
        
        if(gotNode) {
            int h = height(root->left);
            mnTime = max(mnTime, h + targetDisFromRoot - disFromRoot);
            return;
        }

        
    }

  public:
    int minTime(Node* root, int target) {
        // Your code goes here
        mnTime = 0;
        
        minTimeUtil(root, target, 0);
        
        return mnTime;
    }
};