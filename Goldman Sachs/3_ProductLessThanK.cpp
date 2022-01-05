//Time Complexity : O(n)
class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        long long curr = a[0];
        int begin = 0, countOfSubarrays = a[0] < k ? 1 : 0;
        
        for(int i=1; i<n; i++) {
            curr = curr * a[i];
            
            if(curr<k) {
                countOfSubarrays += (i - begin + 1);
            } else {
                while(curr>=k && begin<=i) {
                    curr = curr / a[begin++];
                }
                countOfSubarrays += (i - begin + 1);
            }
        }
        
        return countOfSubarrays;
    }
};