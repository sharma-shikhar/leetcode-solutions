class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int curSum = 0;
        int minLen = numeric_limits<int>::max();
        
        int low = 0;
        int high = 0;
        
        while (high < nums.size()) {
            curSum += nums[high];
            
            while (low <= high && curSum - nums[low] >= s) {
                curSum -= nums[low];
                low++;
            }
            
            if (curSum >= s && high - low + 1 < minLen)
                minLen = high - low + 1;
            
            high++;
        }
        
        return (minLen == numeric_limits<int>::max()) ? 0 : minLen;
        
    }
};