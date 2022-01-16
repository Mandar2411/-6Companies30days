class Solution {
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n) {
       // Your code here
        stack<int> st; 
        st.push(0); 
        vector <int> span;
       
        span.push_back(1);
  
        for(int i=1; i<n; i++) { 
            while (!st.empty() && price[st.top()] <= price[i]) 
                st.pop(); 
  
            int sp = (st.empty()) ? (i+1) : (i-st.top()); 
        
            span.push_back(sp); 
            st.push(i); 
        } 
    
        return span;
    }
};