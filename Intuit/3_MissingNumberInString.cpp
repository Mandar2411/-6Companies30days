int toInt(string tmp) {
    int res = 0;
    for(int i=0; i<tmp.length(); i++)
        res = res*10 + (tmp[i]-'0');
    return res;
}

int countDigits(int n) {
    int count = 0;
    while(n>0) {
        count++;
        n /= 10;
    }
    return count;
}


int missingNumber(const string& str) {
    // Code here
    int n = str.length(), missing = -1;
    for(int firstLen=1; firstLen<=6 && firstLen<n; firstLen++) {
        string firstNo = "";
        
        int i = 0;
        for(int i=0; i<firstLen; i++)
            firstNo += str[i];
            
        int prev = toInt(firstNo), count = 0, j = firstLen, k = firstLen;
        string curr = "", next = "";
        bool valid = true;
        
        while(j < n) {
            int nextDigits = countDigits(prev+1);
            int nexttoNextDIgits = countDigits(prev+2);
            
            while(j<n && nextDigits--) {
                curr += str[j++];
            }
            while(k<n && nexttoNextDIgits--) {
                next += str[k++];
            }
    
            int currNo = toInt(curr);
            int nextNo = toInt(next);
            
            if(currNo == prev+1) {
                prev = currNo;
                curr = next = "";
                k = j;
            } else if(nextNo == prev+2) {
                missing = prev+1;
                prev = nextNo;
                j = k;
                curr = next = "";
            } else {
                valid = false;
                break;
            }
        }
        
        if(missing != -1 && valid == true)
            return missing;
        missing = -1;
    }
    
    return missing;
}