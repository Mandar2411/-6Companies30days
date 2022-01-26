class Solution {
    bool detectCycleUtil(vector<vector<int>> &adj,vector<int> &vis, int v) {
        if(vis[v] == 1)
            return true;
        if(vis[v] == 2)
            return false;
        
        vis[v] = 1;   
        for(int i=0; i<adj[v].size(); i++)
            if(detectCycleUtil(adj, vis, adj[v][i]))
                return true;
        
        vis[v] = 2;   
        return false;
    }
    
    bool detectCycle(vector<vector<int>> &adj, int n) {
        vector<int> vis(n, 0);
        for(int i=0; i<n; i++)
            if(!vis[i])
                if(detectCycleUtil(adj, vis, i))
                    return true;
        return false;
    }
    
    void dfs(vector<vector<int>> &adj, int u, vector<bool> &vis, stack<int> &topSort) {
        vis[u] = true;
        for(int v: adj[u])
            if(!vis[v])
                dfs(adj, v, vis, topSort);
        
        topSort.push(u);
    }    
    
  public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        vector<vector<int>> adj(numCourses);
        
        for(int i=0; i<n; i++)
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        
        vector<int> res;
        if(detectCycle(adj,numCourses))
            return res;        
        
        stack<int> topSort;
        vector<bool> vis(numCourses, false);
        
        for(int i=0; i<numCourses; i++)
            if(!vis[i])
                dfs(adj, i, vis, topSort);
        
        while(!topSort.empty()) {
            res.push_back(topSort.top());
            topSort.pop();
        }
        return res;
    }
};