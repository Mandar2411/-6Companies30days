class Solution {
    public:
    //Function to connect nodes at same level.
    void connect(Node *root) {
        // Your Code Here
        queue<Node*> level;
        level.push(root);
        
        while(!level.empty()) {
            int currLevelSize = level.size();
            Node* curr = NULL;
            
            for(int i=0; i<currLevelSize; i++) {
                
                Node *prev = curr;
                curr = level.front();
                level.pop();
                
                if(prev != NULL) {
                    prev->nextRight = curr;
                }
                
                if(curr->left != NULL)
                    level.push(curr->left);
                if(curr->right != NULL)
                    level.push(curr->right);
            }
            curr->nextRight = NULL;
        }
    }    
      
};
