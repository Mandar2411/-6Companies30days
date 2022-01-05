// Time Complexity : O( N*|S|*log|S| )
// Auxilary Space  : O( N*|S| ) 
class Solution{
  public:
  
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        //code here
        int n = string_list.size();
        vector<vector<string>> anagrams;
        
        //Vector to store the words and their corresponding indices in given vector of strings
        vector<pair<string, int>> words;
        
        for(int i=0; i<n; i++) {
            words.push_back({string_list[i], i});
            //Sorting the word 
            sort(words[i].first.begin(), words[i].first.end());
        } 
        
        //Sorting words to group anagrams together
        sort(words.begin(), words.end());
        
        //Vector to store current list of Anagrams
        vector<string> currListOfAnagrams;
        
        for(int i=0; i<n; i++) {
            if(i == 0) {
                int index = words[i].second;
                currListOfAnagrams.push_back(string_list[index]);
                continue;
            }
            
            string currString = words[i].first;
            string prevString = words[i-1].first;
            
            int currStringIndex = words[i].second;
            
            if(currString == prevString) {
                //Add string to the current list of anagrams
                currListOfAnagrams.push_back(string_list[currStringIndex]);
            } else {
                //Put the current list of Anagrams into answer
                anagrams.push_back(currListOfAnagrams);
                currListOfAnagrams.clear();
                currListOfAnagrams.push_back(string_list[currStringIndex]);
            }
        }
        //Putting last list of Anagrams
        anagrams.push_back(currListOfAnagrams);
        
        return anagrams;
    }
};