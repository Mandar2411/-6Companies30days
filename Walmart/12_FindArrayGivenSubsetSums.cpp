class Solution {
    vector<int> recoverArrayUtil(int n, vector<int>& sums){
        bool zero = false;
        
        for(int num: sums) {
            if(num == 0){
                zero = true;
            }
        }
        if(!zero) {
            return {};
        }
        if(n==1) {
            return {sums[0]+sums[1]};
        }
        
        int len = sums.size();
        for(int i=1; i<=len/2; i++) {
            int j = i;
            int diff = sums[j] - sums[0];
            
            
            vector<int> next;
            vector<int> taken(len,0);
            
            next.push_back(sums[0]);
            taken[j] = 1;
            
            j++;
            
            for(int k=1; k<len; k++){
                if(taken[k]) {
                    continue;
                }
                j = max(j, k+1);
                
                while(sums[j]-sums[k]<diff && j<len) {
                    j++;
                }
                
                if(j==len || sums[j]-sums[k]>diff) { 
                    break;
                }
                
                taken[j] = 1;
                j++;
                next.push_back(sums[k]);
            }
           
            if(next.size()!=len/2){
                continue;
            }
            auto vec = recoverArrayUtil(n-1,next);
            if(!vec.empty()){
                vec.push_back(diff);
                return vec;
            }
            
            for(int &num:next){
                num += diff;
            }
            auto vec2 = recoverArrayUtil(n-1,next);
            if(!vec2.empty()){
                vec2.push_back(-diff);
                return vec2;
            }            
        }
        return {};
    }

  public:
    vector<int> recoverArray(int n, vector<int>& sums) {
        sort(sums.begin(), sums.end());
        return recoverArrayUtil(n, sums);
    }
};