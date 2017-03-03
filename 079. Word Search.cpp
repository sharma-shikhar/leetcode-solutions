class Solution {
    // for debugging purposes
    void printBoard(vector<vector<char>> & board) {
        for (int i=0; i<board.size(); i++) {
            for (int j=0; j<board[0].size(); j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }
    
    bool invalidIndex(vector<vector<char>> & board, int i, int j) {
        return i < 0 || j < 0 || 
            i >= board.size() || j >= board[0].size();
    }
    
    bool find(string & word, int index, vector<vector<char>> & board, int i, int j) {
        if (index == word.size())
            return true;
        if (invalidIndex(board, i, j)) 
            return false;
        if (word[index] != board[i][j])
            return false;
        
        //printBoard(board);
        
        bool found = false;    
        char save = board[i][j];
        board[i][j] = '-';
        
        found = find(word, index + 1, board, i + 1, j);
        if (!found)
            found = find(word, index + 1, board, i, j + 1);
        if (!found)
            found = find(word, index + 1, board, i - 1, j);
        if (!found)
            found = find(word, index + 1, board, i, j - 1);
        
        board[i][j] = save;
        return found;
    }
    
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i=0; i<board.size(); i++) {
            for (int j=0; j<board[0].size(); j++) {
                if (find(word, 0, board, i, j))
                    return true;
            }
        }
        return false;
    }
};