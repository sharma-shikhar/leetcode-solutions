// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
    int _firstBadVersion(int low, int high) {
        if (low >= high)
            return low;
            
        int mid = low + (high-low)/2;
        
        if (isBadVersion(mid))
            return _firstBadVersion(low, mid);
        else
            return _firstBadVersion(mid + 1, high);
    }
public:
    int firstBadVersion(int n) {
        if (isBadVersion(1))
            return 1;
        else
            return _firstBadVersion(1, n);
    }
};