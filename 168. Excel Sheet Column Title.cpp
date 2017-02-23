class Solution {
public:
    string convertToTitle(int n) {
        const int ALPHABETLEN = 26;
        string buf = "";
        
        while (n) {
            int rem = (n-1) % ALPHABETLEN;
            char ch = 'A' + rem;
            buf = ch + buf;
            n = (n-1) / ALPHABETLEN;
        }
        
        return buf;
    }
};