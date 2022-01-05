class Solution{
    
    string decodedStringUtil(string &s, int &i) {
        string decodedString;
        
        while(i < s.length() && s[i] != ']') {
            if(isdigit(s[i])) {
                int noOfTimes = 0;
                
                while(i < s.length() && isdigit(s[i]))
                    noOfTimes = noOfTimes*10 + s[i++] - '0';
                
                i++;
                string str = decodedStringUtil(s, i);
                
                while(noOfTimes--)
                    decodedString += str;
                
                i++;
                
            } else {
                decodedString += s[i++];
            }
        }
        
        return decodedString;
    }
    
public:
    string decodedString(string s){
        // code here
        int i = 0;
        return decodedStringUtil(s, i);
    }
};