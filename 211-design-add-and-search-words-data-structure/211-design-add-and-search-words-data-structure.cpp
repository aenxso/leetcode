class WordDictionary {
    
public:
    // create an hashmap which takes an int (size of word) and string (word itself)
    // when searching for a word, use size of word only search that section of the dictionary
    
    WordDictionary() {}
    
    void addWord(string word) {
        dict[word.size()].push_back(word);
    }
    
    bool search(string word) {
        for(auto s : dict[word.size()]) {
            if(match(s, word)) {
                return true;
            }
        }
        return false;
    }
    
private:
    unordered_map<int, vector<string>> dict;
    
    bool match(string a, string b) {
        for(int i = 0; i < a.size(); i++) {
            if(b[i] == '.') {
                continue;
            }
            if(a[i] != b[i]) {
                return false;
            }
        }
        return true;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */