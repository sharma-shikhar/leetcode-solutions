class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int curIndex = 0;
        int i=0;

        while (i < nums.size()) {
            if (nums[i])
                nums[curIndex++] = nums[i];
            i++;
        }
        
        while (curIndex < nums.size())
            nums[curIndex++] = 0;
    }
};