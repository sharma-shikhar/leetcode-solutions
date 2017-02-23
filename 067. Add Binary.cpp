class Solution {
    void padWithZeroes(string & str, int numZeroes) {
        string s(numZeroes, '0');
        str = s + str;
    }
    int bdigit(char ch) { // assumes input belongs to {0, 1}
        return ch - '0';
    }
    int bSum(int a, int b, int c) {
        return (a + b + c) % 2;
    }
    int bCarry(int a, int b, int c) {
        return (a + b + c) / 2;
    }
    
public:
    string addBinary(string a, string b) {
        int maxLen = max(a.size(), b.size());
        string result = "";
        
        padWithZeroes(a, maxLen - a.size());
        padWithZeroes(b, maxLen - b.size());
        
        int carry = 0;
        for (int i = a.size()-1; i >= 0; i--) {
            int sum = bSum(bdigit(a[i]), bdigit(b[i]), carry);
            carry = bCarry(bdigit(a[i]), bdigit(b[i]), carry);
            result = to_string(sum) + result;
        }
        if (carry)
            result = to_string(carry) + result;
        
        return result;
    }
};