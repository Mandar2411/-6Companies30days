class Solution {
public:
    string printMinNumberForPattern(string str){
        // code here 
        string minNumber = "";
        int n = str.length();
        
        stack<int> st;
	    for(int i=0; i<=str.length(); i++) {
		    st.push(i+1); 
		
		    if(str.length()==i || str[i]=='I') { 
			    while(!st.empty()) { 
				    minNumber += ('0' + st.top());
				    st.pop();
			    } 
		    }
	    }
	    return minNumber;
    }
};