class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k) {
        deque <int> dq;
        int i;
        vector<int> res;
        
        for(i=0; i<k; i++) {
            while(!dq.empty() && arr[i]>=arr[dq.back()])
                dq.pop_back();
           dq.push_back(i);
        }
    
        for(i=k; i<n; i++) {
            res.push_back(arr[dq.front()]);
        
            while(!dq.empty() && dq.front()<=i-k)
               dq.pop_front();
           
            while(!dq.empty() && arr[i]>=arr[dq.back()])
               dq.pop_back();
           
            dq.push_back(i);   
        }
        res.push_back(arr[dq.front()]);
        
        return res;
    }
};
