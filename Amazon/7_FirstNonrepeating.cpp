class Solution {
	public:
		string FirstNonRepeating(string A) {
		    // Code here
		    string res = "";
		    vector<int> count(26, 0);
		    queue<char> q;
		    int n = A.length();
		    
		    for(int i=0; i<n; i++) {
		        count[A[i]-'a']++;
		        q.push(A[i]);
		        
		        while(!q.empty() && count[q.front()-'a'] > 1) {
		            q.pop();
		        }
		        
		        if(q.empty())
		            res += '#';
		        else
		            res += q.front();
		    }
		    return res;
		}

};