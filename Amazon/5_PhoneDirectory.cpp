class Trie {
public:
    bool endOfWord;
    unordered_map<char, Trie*>mp;
    Trie() {
        endOfWord = 0;
    }
    
    void insert(string word, Trie* root) {
        Trie* curr = root;
        
        int i = 0;
        while(i < word.size()) {
            if(curr->mp.find(word[i]) == curr->mp.end()) {
                curr->mp[word[i]] = new Trie();
            }
            curr = curr->mp[word[i]];
            i++;
        }
        curr->endOfWord = 1;
    }
    
    void search(Trie* curr, vector<string>&res, string &prefix) {
        
        if(curr->endOfWord) 
            res.push_back(prefix);
        
        for(char c='a'; c<='z'; c++) {
            if(curr->mp.find(c)==curr->mp.end()) 
                continue;
            
            prefix.push_back(c);
            
            search(curr->mp[c], res, prefix);
            
            prefix.pop_back();
        }
    }
};

class Solution {
    
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s) {
        // code here
        Trie* root = new Trie();
        for(int i=0; i<n; i++) {
            root->insert(contact[i], root);
        }
        
        vector<vector<string>> res;
        string prefix = "";
        Trie* curr = root;
        
        for(char c: s) {
            prefix += c;
            if(curr->mp.find(c) == curr->mp.end()) 
                break;
            else 
                curr = curr->mp[c];
                
            vector<string> temp;
            
            root->search(curr, temp, prefix);
            
            if(temp.empty()) 
                break;
            else 
                res.push_back(temp);
        }
        while(res.size() < s.size()){
            res.push_back({"0"});
        }
        
        return res;
    }
};