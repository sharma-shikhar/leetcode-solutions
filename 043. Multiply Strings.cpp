class Solution {
    int getDigit(char d) {
        return d - '0'; // assumption: input is {'0', '1', ..., '9'}
    }
    pair<int, int> getSingleDigitMultiplyRes(int d1, int d2, int c) {
        int res = d1*d2 + c;
        return make_pair(res%10, res/10);
    }
    pair<int, int> getSingleDigitAddRes(int d1, int d2, int c) {
        int res = d1 + d2 + c;
        return make_pair(res%10, res/10);
    }
    void padWithZeroes(string & str, int numZeroes) {
        str = string(numZeroes, '0') + str;
    }
    string add(string s1, string s2) {
        int maxLen = max(s1.size(), s2.size());
        if (s1.size() < maxLen)
            padWithZeroes(s1, maxLen - s1.size());
        if (s2.size() < maxLen)
            padWithZeroes(s2, maxLen - s2.size());
        
        string result = "";
        int carry = 0;
        
        int i = maxLen - 1;
        while (i >= 0) {
            pair<int, int> res = getSingleDigitAddRes(getDigit(s1[i]), getDigit(s2[i]), carry);
            int sum = res.first;
            carry = res.second;
            
            result = to_string(sum) + result;
            i--;
        }
        if (carry)
            result = to_string(carry) + result;
        
        return result;
        
    }
    string multiply(string str, char ch) {
        int digit = getDigit(ch);
        
        string result = "";
        int carry = 0;
        int i = str.size() - 1;
        
        while (i >= 0) {
            pair<int, int> res = getSingleDigitMultiplyRes(getDigit(str[i]), digit, carry);
            int mul = res.first;
            carry = res.second;
            
            result = to_string(mul) + result;
            i--;
        }
        
        if (carry)
            result = to_string(carry) + result;
            
        return result;
        
    }
public:
    string multiply(string num1, string num2) {
        string result = "";
        
        if (num1 == "0" || num2 == "0") // otherwise, this code outputs: "0000.." if the other number is larger
            return "0";
            
        for (int i = num1.size()-1; i>= 0; i--) {
            string mul = multiply(num2, num1[i]);
            int shift = num1.size() - i - 1;
            result = add(result, mul + string(shift, '0'));
        }
        return result;
    }
};