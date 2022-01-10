class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        vector<int> pre(n);
        pre[n-1] = 1;
        for(int i = n-2; i>=0; i--) {
            if(arr[i] > arr[i+1]) {
                pre[i] = 1 + pre[i+1];
            } else {
                pre[i] = 1;
            }
        }
        
        int curr = 1, res = 0;
        for(int i = 1; i<n; i++) {
            if(arr[i]>arr[i-1]) {
                curr++;
            } else {
                curr = 1;
            }
            if(curr>1 && pre[i]>1)
                res = max(res, curr+pre[i]-1);
        }
        
        return res;
    }
};