class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        string upto_here = "";
        string longest = "";
        int index;
    
        for (int i=0; i<s.size(); i++) {
            if (upto_here == "")
                upto_here = s[i];
            else if ((index = upto_here.find(s[i])) != string::npos) {
                upto_here = upto_here.substr(index + 1) + s[i];
            } else
                upto_here += s[i];
            
            if (upto_here.size() > longest.size())
                longest = upto_here;
        }
        return longest.size();
    }
};