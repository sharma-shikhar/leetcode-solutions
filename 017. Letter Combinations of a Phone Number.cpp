class Solution {
    void getCombinations(string digits, int index, string & buf, vector<string> & results, unordered_map<char, string> &mapper) {
        if (index == digits.size()) {
            results.push_back(buf);
            return;
        }
        
        char curDigit = digits[index];
        for (char ch : mapper[curDigit]) {
            buf += ch;
            getCombinations(digits, index+1, buf, results, mapper);
            buf.resize(buf.size() - 1);
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> mapper;
        mapper['0'] = "0";
        mapper['1'] = "1";
        mapper['2'] = "abc";
        mapper['3'] = "def";
        mapper['4'] = "ghi";
        mapper['5'] = "jkl";
        mapper['6'] = "mno";
        mapper['7'] = "pqrs";
        mapper['8'] = "tuv";
        mapper['9'] = "wxyz";
        
        
        vector<string> results;
        if (!digits.size())
            return results;
        string buf;
        getCombinations(digits, 0, buf, results, mapper);
        return results;
        
    }
};