class Solution {
public:
    string countAndSay(int n) {
        if (!n) return "";
        string res = "1";
        
        for (int i=1; i<n; i++) {
            string buf = "";
            int count=1;
            int j = 1;
            
            while (j < res.size()) {
                if (res[j] != res[j-1]) {
                    buf += to_string(count) + res[j-1];
                    j++;
                    count = 1;
                }
                else {
                    count++;
                    j++;
                }
            }
            if (count)
                buf += to_string(count) + res[res.size() - 1];
            
            res = buf;
        }
        
        return res;
    }
};