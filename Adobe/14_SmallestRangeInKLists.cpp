class element {
 public:
    int val;
    int index;
    int row;
 
    element(int val, int index, int row) {
        this->val = val;
        this->index = index;
        this->row = row;
    }
};

struct myCmp {
    bool operator()(element a, element b) {
        return a.val > b.val;
    }
};


class Solution {
    public:
    pair<int,int> findSmallestRange(int arr[][N], int n, int k) {
        //code here
        
        priority_queue<element, vector<element>, myCmp> minHeap;
        
        int mn=INT_MAX, mx=INT_MIN, range=INT_MAX;
        
        for(int i=0;i<k;++i){ 
            minHeap.push(element(arr[i][0], 0, i));
            mn = min(mn, arr[i][0]);
            mx = max(mx, arr[i][0]);
        }
        
        range = mx - mn;
        int res_mn = mn, res_mx = mx;
        
        while(1) {
            element tmp = minHeap.top();
            minHeap.pop();
            
            int nextIndex = tmp.index + 1;
            int row = tmp.row;
            
            if(nextIndex == n) {
                return {res_mn, res_mx};
            }
            
            minHeap.push(element(arr[row][nextIndex], nextIndex, row));
            if(mx < arr[row][nextIndex])
                mx = arr[row][nextIndex];
            
            mn = minHeap.top().val;
            
            
            if(range > (mx-mn)) {
                range = mx - mn;
                res_mn = mn;
                res_mx = mx;
            }
        }
        return {res_mn, res_mx};
    }
};