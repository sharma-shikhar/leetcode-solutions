class Solution {
    
    vector<string> createSpaceSeparatedWords(vector<vector<int>> & dp, string s, int index) {
        vector<string> results;
        
        for (int size : dp[index]) {
            int subproblemSize =  index - size;
            if (subproblemSize) {
                vector<string> subResults = createSpaceSeparatedWords(dp, s, subproblemSize);
                for (string subStr : subResults) {
                    results.push_back(subStr + " " + s.substr(index - size, size));
                }
            }
            else {
                results.push_back(s.substr(index - size, size));
            }
        }
        
        return results;
    }
    
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        if (!s.size())
            return vector<string>();
        
        vector<vector<int>> dp(s.size() + 1, vector<int>());
        
        dp[0].push_back(0);
        
        for (int i = 1; i <= s.size(); i++) {
            int j = i-1;
            
            while (j >= 0) {
                string rest = s.substr(j, i-j);
                if (!dp[j].empty() && find(wordDict.begin(), wordDict.end(), rest) != wordDict.end())
                    dp[i].push_back(rest.size());
                j--;
            }
        }
        
        return createSpaceSeparatedWords(dp, s, s.size());
    }
};