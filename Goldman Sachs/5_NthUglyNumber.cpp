class Solution{
public:	
	// #define ull unsigned long long
	ull getNthUglyNo(int n) {
	    // code here
	    set<ull> uglyNumbers;
	    uglyNumbers.insert(1);
	    
	    while((n--)>1) {
	        
	        ull frontUglyNumber = *uglyNumbers.begin();
	        uglyNumbers.erase(uglyNumbers.begin());
	        
	        uglyNumbers.insert(frontUglyNumber * 2);
	        uglyNumbers.insert(frontUglyNumber * 3);
	        uglyNumbers.insert(frontUglyNumber * 5);
	    }
	    
	    return *uglyNumbers.begin();
	}
};