class Solution {
  public:
    //Function to return the name of candidate that received maximum votes.
    vector<string> winner(string arr[], int n) {
        // Your code here
        // Return the string containing the name and an integer
        // representing the number of votes the winning candidate got
        map<string, int> mp;
        vector<string> res;
        string ans = "";
        int ansCount = 0;
        
        for(int i=0; i<n; i++) 
            mp[arr[i]]++;
        
        for(auto it : mp) {
            if(it.second > ansCount) {
                ans = it.first;
                ansCount = it.second;
            }
        }
        res.push_back(ans);
        res.push_back(to_string(ansCount));
        return res;
    }
};