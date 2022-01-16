class Solution {  
  public:
	void dfs(int i, int V, vector<int> adj[], vector<bool> &visited) {
	    visited[i] = true;
	    for(auto v : adj[i]) {
	        if(!visited[v]) {
	            dfs(v, V, adj, visited);
	        }
	    }
	}
	
	int connectedComponents(vector<int> adj[], int V) {
	    vector<bool> visited(V, false);
	    int count = 0;
	    
	    for(int i=0; i<V; i++) {
	        if(!visited[i]) {
	            dfs(i, V, adj, visited);
	            count++;
	        }
	    }
	    return count;
	}
    //Function to find if the given edge is a bridge in graph.
    int isBridge(int V, vector<int> adj[], int c, int d) {
        // Code here
        int componentsWithEdge = connectedComponents(adj, V);
        
        vector<int> adj2[V];
        
        for(int i=0; i<V; i++) {
            for(int j=0; j<adj[i].size(); j++) {
                if((i==c && adj[i][j]==d) || (i==d && adj[i][j]==c))
                {
                    continue;
                }
                adj2[i].push_back(adj[i][j]);
            }
        }
        
        int componentsWithoutEdge = connectedComponents(adj2, V);
        
        if(componentsWithoutEdge == componentsWithEdge)
            return 0;
        else
            return 1;
    }
};