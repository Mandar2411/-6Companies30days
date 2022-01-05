//Time Complexity : O(|src|)
string encode(string src)
{
    string encoded = "";
    int currLength = 1; // Count to store the current lenght of string of same characters
    int n = src.length();
    
    for(int i=1; i<n; i++) {
        if(src[i] != src[i-1]) {
            encoded += src[i-1];
            encoded += ('0' + currLength);
            currLength = 1;
        } else {
            currLength++;
        }   
    }
    encoded += src[n-1];
    encoded += ('0' + currLength);
    
    return encoded;
}   