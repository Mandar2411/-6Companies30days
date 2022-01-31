class Solution {
  public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, 
                                                                            int start, int end) {
        int m = edges.size();
        vector<vector<pair<int, double>>> adj(n);
        for(int i=0; i<m; i++) {
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});   
        }
        vector<bool> vis(n, false);
        
        priority_queue<pair<float, int>> pq;
        pq.push({1.0, start});
        
        vector<float> mxProb(n, 0.0);
        mxProb[start] = 1.0;
        
        while(!pq.empty()) {
            pair<float, int> top = pq.top();
            pq.pop();
            float prob = top.first;
            int node = top.second;
            
            if(!vis[node]) {
                vis[node] = true;
                for(auto &v: adj[node]) {
                    if (mxProb[v.first] < v.second*prob) {
                        mxProb[v.first] = v.second*prob;
						pq.push({mxProb[v.first], v.first});
                    }
                }
            }
        }
        return mxProb[end];
    }
};