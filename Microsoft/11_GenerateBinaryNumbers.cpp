string binary(int n) {
    string binary = "";
    while(n) {
        binary += to_string(n%2);
        n = n/2;
    }
    reverse(binary.begin(), binary.end());
    
    return binary.substr(binary.find('1'));
}

vector<string> generate(int N) {
	// Your code here
	vector<string> res;
    string s="";
	for(int i=1; i<=N; i++) {
	    string bin = binary(i);
	    res.push_back(bin);
	}
	return res;
}