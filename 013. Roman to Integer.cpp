class Solution {
    int romanToInt(char ch) {
        switch(ch) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0;
        }
    }
public:
    int romanToInt(string s) {
        transform(s.begin(), s.end(), s.begin(), ::toupper);
        
        int sum = 0;
        int i = 0;
        while (i < s.size()) {
            if (i+1 < s.size() && romanToInt(s[i]) < romanToInt(s[i+1])) {
                sum += romanToInt(s[i+1]) - romanToInt(s[i]);
                i += 2;
            }
            else {
                sum += romanToInt(s[i]);
                i++;
            }
        }
        return sum;
    }
};