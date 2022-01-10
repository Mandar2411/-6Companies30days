class Solution
{
    public:
    //Function to serialize a tree and return a list containing nodes of tree.
    vector<int> serialize(Node *root) {
        //Your code here
        vector<int> res;
        
        if(root == NULL)
            return res;
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()) {
            Node* curr = q.front();
            q.pop();
            
            if(curr == NULL)
                res.push_back(-1);
            else
                res.push_back(curr->data);
            
            if(curr != NULL) {
                q.push(curr->left);
                q.push(curr->right);
            }    
        }
        return res;
    }
    
    //Function to deserialize a list and construct the tree.
    Node * deSerialize(vector<int> &A) {
        //Your code here
        if(A.size() == 0)
            return NULL;
        
        queue<Node*> q;
        Node* root = new Node(A[0]);
        q.push(root);
        
        int index = 1;
        while(!q.empty()) {
            Node *curr = q.front();
            q.pop();
            
            int val = A[index++];
            
            if(val == -1) {
                curr->left = NULL;
            } else {
                Node * leftNode = new Node(val);
                curr->left = leftNode;
                q.push(leftNode);
            }
            
            val = A[index++];
            
            if(val == -1) {
                curr->right = NULL;
            } else {
                Node * rightNode = new Node(val);
                curr->right = rightNode;
                q.push(rightNode);
            }
        }
        return root;
    }

};