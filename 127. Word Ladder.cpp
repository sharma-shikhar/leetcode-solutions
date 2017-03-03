class Solution {
    // for debugging purposes
    void print_(vector<string> & wordList) {
        cout << "wordList: ";
        for (auto s : wordList)
            cout << s << " ";
        cout << endl;
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int>> q;
        
        wordList.erase(find(wordList.begin(), wordList.end(), beginWord));
        q.push(make_pair(beginWord, 1));
        
        while (!q.empty()) {
            pair<string, int> p = q.front(); q.pop();
            string word = p.first;
            int pathlen = p.second;
            
            if (word == endWord)
                return pathlen;
            
            for (int i=0; i<word.size(); i++) {
                for (char ch='a'; ch<='z'; ch++) {
                    if (ch != word[i]) {
                        string newWord = word;
                        newWord[i] = ch;
                        
                        if (find(wordList.begin(), wordList.end(), newWord) != wordList.end()) {
                            wordList.erase(find(wordList.begin(), wordList.end(), newWord));
                            q.push(make_pair(newWord, pathlen + 1));
                        }
                    }
                }
            }
        }

        return 0;
    }
};