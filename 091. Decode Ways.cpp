class Solution {
    int strToInt(string str) {
        stringstream ss(str);
        int val;
        return ss >> val ? val : 0;
    }
    bool isValidTwoLetter(string s) {
        int n = strToInt(s); 
        return  n >= 10 && n <= 26;
    }
    bool isValidOneLetter(char ch) {
        return ch >= '1' && ch <= '9';
    }
public:
    int numDecodings(string s) {
        if (!s.size()) return 0;
        
        int *ways = new int[s.size() + 1];
        fill_n(ways, s.size() + 1, 0);
        ways[0] = 1;
        ways[1] = isValidOneLetter(s[0]) ? 1 : 0;
        
        for (int i=2; i<=s.size(); i++) {
            if (isValidOneLetter(s[i-1]))
                ways[i] += ways[i-1];
            
            if (isValidTwoLetter(s.substr(i-2, 2)))
                ways[i] += ways[i-2];
        }

        int val = ways[s.size()];
        delete[] ways;
        return val;
    }
};