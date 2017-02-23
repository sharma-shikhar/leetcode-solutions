class Solution {
    bool isValid(char ch) {
        return ch >= 'a' && ch <= 'z' ||
               ch >= '0' && ch <= '9';
    }
    
public:
    bool isPalindrome(string s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        
        int low = 0;
        int high = s.size() - 1;
        
        while (low < high) {
            while (low < s.size() && !isValid(s[low]))
                low++;
            while (high >= 0 && !isValid(s[high]))
                high--;
            
            if (s[low] != s[high])
                return false;
            
            low++;
            high--;
        }
        return true;
    }
};