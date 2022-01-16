class Solution {
public:
	bool isPossible(int N, vector<pair<int, int>>& prerequisites) {
	    // Code here
	    vector<vector<int>> g(N);
	    vector<int> degree(N, 0);
	    
	    for(auto pi : prerequisites) {
            g[pi.second].push_back(pi.first);
            degree[pi.first]++;
        }
        
	    queue<int> q;
        for(int i=0; i<N; i++)
            if(degree[i] == 0) 
                q.push(i);
                
        int count = 0;
        while(!q.empty()) {
            int curr = q.front(); 
            q.pop(); 
            count++;
            for(auto v: g[curr]) {
                degree[v]--;
                if(degree[v] == 0) {
                    q.push(v);
                }
            }
        }
        
        return (count == N);
	}
};