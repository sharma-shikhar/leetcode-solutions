class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (!nums.size())
            return 0;
            
        int index = 0;
        int cur = 1;
        
        while (cur < nums.size()) {
            while (cur < nums.size() && nums[cur] == nums[index])
                cur++;
            if (cur == nums.size())
                break;
            
            nums[++index] = nums[cur++];
        }
        
        return index + 1;
    }
};