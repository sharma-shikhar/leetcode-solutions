class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if (s.size() == 0) return false;
            
        vector<bool> result(s.size() + 1, false);
        result[0] = true;
        
        for (int i=1; i<=s.size(); i++) {
            int j = i - 1;
            while (j >= 0) {
                string rest = s.substr(j, i - j);
                if (result[j] && find(wordDict.begin(), wordDict.end(), rest) != wordDict.end()) {
                    result[i] = true;
                    break;
                }
                j--;
            }
        }

        return result[s.size()];
    }
};