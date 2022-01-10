class Solution{
public:	

	void matchPairs(char nuts[], char bolts[], int n) {
	    // code here
	    char sample[9] = {'!','#','$','%','&','*','@','^','~'};
	    vector<int> hashmap(9, 0);
	    
	    for(int i=0; i<n; i++) {
	        if(nuts[i] == '!') hashmap[0]++;
	        else if(nuts[i] == '#') hashmap[1]++;
	        else if(nuts[i] == '$') hashmap[2]++;
	        else if(nuts[i] == '%') hashmap[3]++;
	        else if(nuts[i] == '&') hashmap[4]++;
	        else if(nuts[i] == '*') hashmap[5]++;
	        else if(nuts[i] == '@') hashmap[6]++;
	        else if(nuts[i] == '^') hashmap[7]++;
	        else hashmap[8]++;
	    }
	    int index = 0;
	    for(int i=0; i<9; i++) {
	        if(hashmap[i] != 0) {
	            nuts[index] = sample[i];
	            bolts[index] = sample[i];
	            index++;
	        }
	    }
	    
	}

};