class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 3)
            return nums.size();

        const int NUM_DUPS_ALLOW = 2;

        int finalIndex = 0;
        int count = 1;
        int curIndex = 1;
        
        while (curIndex < nums.size()) {
            if (nums[curIndex] != nums[finalIndex]) {
                nums[++finalIndex] = nums[curIndex++];
            }
            else { //duplicates
                int dup = nums[curIndex];
                while (count < NUM_DUPS_ALLOW && curIndex < nums.size() && nums[curIndex] == dup) {
                    nums[++finalIndex] = nums[curIndex++];
                    count++;
                }
                while (curIndex < nums.size() && nums[curIndex] == dup)
                    curIndex++;
                count = 1;
            }
        }
        return finalIndex + 1;
    }
};