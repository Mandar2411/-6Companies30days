class Solution {
    void dfs(int src, vector<int> adj[], int k, vector<bool> &vis, string &order) {
        vis[src] = true;
        for(int v : adj[src]) {
            if(vis[v] == false) {
                dfs(v, adj, k, vis, order);
            }
        }
        order.push_back('a'+src);
    }
    
    public:
    string findOrder(string dict[], int N, int K) {
        //code here
        vector<int> adj[K];
        for(int i=0; i<N-1; i++) {
            string s1 = dict[i];
            string s2 = dict[i+1];
            int m = min(s1.length(), s2.length());
            for(int j=0; j<m; j++) {
                if(s1[j] != s2[j]) {
                    adj[s1[j]-'a'].push_back(s2[j]-'a');
                    break;
                }
            }
        }
        
        vector<bool> vis(K, false);
        string order = "";
        for(int i=0; i<K; i++) {
            if(vis[i]==false) {
                dfs(i, adj, K, vis, order);
            }
        }
        reverse(order.begin(), order.end());
        return order;
    }
};