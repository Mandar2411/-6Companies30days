class Solution {
  public:
    int minInsAndDel(int A[], int B[], int N, int M) {
        // code here
        vector<int> LIS;
        
        unordered_set<int> common;
        for(int i=0; i<M; i++) {
            common.insert(B[i]);
        }
        
        
        for(int i=0; i<N; i++) {
            if(common.find(A[i]) != common.end()) {
                auto it = lower_bound(LIS.begin(), LIS.end(), A[i]);
                
                if(it == LIS.end()) {
                    LIS.push_back(A[i]);
                } else {
                    int index = it - LIS.begin();
                    LIS[index] = A[i];
                }
            }
        }
        
        return (N-LIS.size())+(M-LIS.size());
    }
};