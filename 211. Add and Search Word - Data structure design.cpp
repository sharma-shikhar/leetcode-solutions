// note: this solution is exponential in the number of periods in the search query
// The search space expands by 26 every time a "." is encountered
// example: "b..d" this will take O(26^2) time

const int ALPHABET_LEN = 26;

class Node {
    public:
    bool aWordEndsHere;
    Node *children[ALPHABET_LEN];
    
    Node() : aWordEndsHere(false) {
        fill_n(children, ALPHABET_LEN, nullptr);
    }
};


class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new Node();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        if (word.size() == 0)
            return;
        
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        Node *n = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (!n->children[index])
                n->children[index] = new Node();
            n = n->children[index];
        }
        n->aWordEndsHere = true;        
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    
    bool _search(string word, int index, Node *n) {
        if (word[index] >= 'a' && word[index] <= 'z')
            
        for (char ch : word) {
            int index = ch - 'a';
            n = n->children[index];
            if (!n)
                return false;
        }
        return n->aWordEndsHere;
    }
    
    bool search(string word) {
        if (word.size() == 0)
            return false;
        // lowercase it
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        
        Node *n = root;
        return _search(word, 0, n);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */