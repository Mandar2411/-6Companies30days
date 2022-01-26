class Solution {
    int binarySearch(MountainArray &mountainArr, int target, int low, int high) {
        while(low <= high) {
            int mid = low + (high-low)/2;
            
            int val = mountainArr.get(mid);
            
            if(val == target)
                return mid;
            else if(val < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return -1;
    }
    
    int binarySearch2(MountainArray &mountainArr, int target, int low, int high) {
        while(low <= high) {
            int mid = low + (high-low)/2;
            
            int val = mountainArr.get(mid);
            
            if(val == target)
                return mid;
            else if(val > target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return -1;
    }
    
  public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int low = 0, high = n-1;
        while(low < high) {
            int mid = low + (high-low)/2;
            if(mountainArr.get(mid) < mountainArr.get(mid+1)) {
                low = mid+1;
            } else {
                high = mid-1;
            }
        }
        int peakIndex = high+1;
        
        int index = binarySearch(mountainArr, target, 0, peakIndex);
        if(index != -1)
            return index;

        index = binarySearch2(mountainArr, target, peakIndex+1, n-1);
        return index;
    }
};