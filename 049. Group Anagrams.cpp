class Solution {

public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        
        auto comp = [] (string s1, string s2) -> bool {
            sort(s1.begin(), s1.end());
            sort(s2.begin(), s2.end());
            return s1 < s2;
        };
        sort(strs.begin(), strs.end(), comp);
        
        vector<string> buf;
        
        auto isAnagramaticallyEqual = [] (string s1, string s2) -> bool {
            sort(s1.begin(), s1.end());
            sort(s2.begin(), s2.end());
            return s1 == s2;
        };
        
        for (string str : strs) {
            if (buf.empty() || isAnagramaticallyEqual(str, buf[buf.size() - 1])) {
                buf.push_back(str);
            }
            else {
                result.push_back(buf);
                buf.resize(0);
                buf.push_back(str);
            }
            
        }
        if (!buf.empty())
            result.push_back(buf);
        
        return result;
    }
};