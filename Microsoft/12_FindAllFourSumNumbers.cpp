class Solution {
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        // Your code goes here
        int n = arr.size();
        vector<vector<int>> res;
        sort(arr.begin(), arr.end());
        
        for(int i=0; i<n-1; i++) {
            for(int j=i+1; j<n; j++) {
                int remSum = k-(arr[i]+arr[j]);
                int l = j+1, h = n-1;
                
                while(l < h) {
                    if(arr[l] + arr[h] < remSum)
                        l++;
                    else if(arr[l] + arr[h] > remSum)
                        h--;
                    else { 
                        vector<int> quad = {arr[i], arr[j], arr[l], arr[h]};
                        res.push_back(quad);

                        while(l < h && arr[l] == quad[2]) 
                            l++;
                        while(l < h && arr[h] == quad[3]) 
                            h--;
                    }
                }
                while(j+1 < n && arr[j+1] == arr[j]) 
                    j++;
            }
            while(i+1 < n-1 && arr[i+1] == arr[i]) 
                i++;
        }
        return res;
    }
};