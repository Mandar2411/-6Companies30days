class Solution {
    void dfs(vector<vector<int>> &isConnected, vector<bool> &vis, int src) {
	    vis[src]=true;
        
	    for(int j=0; j<isConnected.size(); j++)
		    if(isConnected[src][j]==1 && !vis[j])
			    dfs(isConnected, vis, j);
    }
  public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(),ans=0;
	    vector<bool>vis(n,false);

	    for(int i=0; i<n; i++) {
		    if(!vis[i]) {
			    ans++;
			    dfs(isConnected, vis, i);
		    }
	    }
	    return ans;
    }
};