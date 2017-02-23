class Solution {
public:
    bool isValid(string str) {
        stack<char> s;
        
        for (char p : str) {
            if (p == '(' || p == '{' || p == '[') {
                s.push(p);
            }
            else if (p == ')' || p == '}' || p == ']') {
                if (s.empty()) return false;
                char match = s.top(); s.pop();
                
                switch(p) {
                    case ')': if (match != '(') return false; break;
                    case '}': if (match != '{') return false; break;
                    case ']': if (match != '[') return false; break;
                }
            }
            else {
                return false;
            }
        }
        
        return s.empty();
    }
};