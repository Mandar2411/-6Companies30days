class Solution {
  public:
    vector<int> find3Numbers(vector<int> arr, int N) {
        // Your code here
        stack<int> st;
        
        for(int i=N-1; i>=0; i--) {
            if(st.empty()) {
                st.push(arr[i]);
            } else {
                while(!st.empty() && st.top() <= arr[i])
                    st.pop();
            
                st.push(arr[i]);
            }
           
            vector<int> res;
            if(st.size() == 3) {
                while(st.size() != 0) {
                    res.push_back(st.top());
                   st.pop();
                }
                return res;
            }
        }
        return {};
    }
};