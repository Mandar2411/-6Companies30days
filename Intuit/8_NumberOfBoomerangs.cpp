class Solution {
  public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n = points.size();
        if(n <= 2)
            return 0;
        vector<map<int, int>> dist(n);
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(j == i)
                    continue;
                dist[i][pow(points[i][0]-points[j][0], 2) + pow(points[i][1]-points[j][1], 2)]++;
            }
        }
        int ans = 0;
        for(int i=0; i<n; i++) {
            for(auto it=dist[i].begin(); it!=dist[i].end(); it++) {
                if(it->second >= 2)
                    ans += (it->second - 1) * it->second; 
            }
        }
        return ans;
    }
};