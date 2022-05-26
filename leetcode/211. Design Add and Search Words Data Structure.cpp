class TrieNode {
public:
    map<char, TrieNode*> children;
    bool isWord;
    
    TrieNode() {
        isWord = false;
    }
};

class WordDictionary {
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* current = root;
        
        for (auto c : word) {
            if (current->children[c] == nullptr) {
                TrieNode* newNode = new TrieNode();
                current->children[c] = newNode;
            }
            current = current->children[c];
        }
        
        current->isWord = true;
    }
    
    bool search(string word) {
        return search(word, root);
    }
    
private:
    TrieNode* root;
    
    bool search(string word, TrieNode* curr) {
        if (curr == nullptr) {
            return false;
        }
        if (word.empty() && curr->isWord) {
            return true;
        }
        
        // if the next char is not a '.' and it is valid, advance the node and remove the current char
        // else if the char is '.', dfs for each child node (all match)
        if (word[0] != '.' && curr->children[word[0]] != nullptr) {
            // if a valid word was found, return true
            if (search(word.substr(1), curr->children[word[0]])) {
                return true;
            }
        }
        else if (word[0] == '.') {
            for (auto p : curr->children) {
                if (search(word.substr(1), p.second)) {
                    return true;
                }
            }
        }
        
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
