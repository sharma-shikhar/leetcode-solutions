class Solution {
public:
    int strStr(string haystack, string needle) {
        // note: this is an inefficient O(mn) brute-force solution
        // Better approach: KMP
        
        int hlen = haystack.size();
        int nlen = needle.length();
        
        for (int i=0; i < hlen-nlen+1; i++) {
            int j = 0;
            while (j < nlen && haystack[i+j] == needle[j])
                j++;
            
            if (j == nlen) // match!
                return i;
        }
        
        return -1;
        
    }
};