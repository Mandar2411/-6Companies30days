class Solution {
    public:
		int CountWays(string str) {
		    // Code here
		    if (!str.size() || str.front() == '0') 
                return 0;
            
            // curr = no of ways to decode message of length i starting from index 0
            // prev = no of ways to decode message of length i-1 starting from index 0
            long curr = 1, prev = 1;
    
            for (int i = 1; i < str.size(); i++) {
        
                if(str[i] == '0') 
                    curr = 0;

                if(str[i - 1] == '1' || str[i - 1] == '2' && str[i] <= '6') {
                    long tmp = curr;
                    curr = (curr + prev) % 1000000007;
                    prev = tmp;
                }
                else {
                    prev = curr;
                }
            }

            return curr;
		}
};