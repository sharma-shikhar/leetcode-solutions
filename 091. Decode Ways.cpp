class Solution {
    int strToInt(string s) {
        int val;
        stringstream ss(s);
        return ss >> val ? val : 0;
    }
    bool validOneLetter(char ch) {
        return ch >= '1' && ch <= '9';
    }
    bool validTwoLetter(string s) {
        int num = strToInt(s);
        return num >= 10 && num <= 26;
    }
public:
    int numDecodings(string s) {
        if (!s.size()) return 0;
        
        vector<int> ways(s.size() + 1, 0);
        ways[0] = 1;
        if (validOneLetter(s[0]))
            ways[1] = 1;
        
        for (int i=1; i<s.size(); i++) {
            if (validOneLetter(s[i]))
                ways[i+1] += ways[i];
            if (validTwoLetter(s.substr(i-1, 2)))
                ways[i+1] += ways[i-1];
        }
        
        return ways[s.size()];
    }
};