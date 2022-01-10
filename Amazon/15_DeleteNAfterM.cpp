class Solution
{
    public:
    void linkdelete(struct Node  *head, int M, int N) {
        //Add code here   
        Node *curr = head;
        while(curr != NULL) {
           
            for(int i=1; i<M && curr!=NULL; i++) {
                curr = curr->next;
            }
            
            if(!curr)
                return;
            
            Node *tmp = curr;
            
            for(int j=0; j<=N && tmp!=NULL; j++) {
                tmp = tmp->next;
            }
            
            curr->next = tmp;
            curr = tmp;
        } 
    }
};
