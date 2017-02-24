const int ALPHABET_LEN = 26;

class Node {
    public:
    bool aWordEndsHere;
    Node *children[ALPHABET_LEN];
    
    Node() : aWordEndsHere(false) {
        fill_n(children, ALPHABET_LEN, nullptr);
    }
};

class Trie {
    Node *root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
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
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        
        Node *n = root;
        for (char ch : word) {
            int index = ch - 'a';
            n = n->children[index];
            if (!n)
                return false;
        }
        return n->aWordEndsHere;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        transform(prefix.begin(), prefix.end(), prefix.begin(), ::tolower);
        
        Node *n = root;
        for (char ch : prefix) {
            int index = ch -'a';
            n = n->children[index];
            if (!n)
                return false;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */