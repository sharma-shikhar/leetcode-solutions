class Solution {
public:
    void sortColors(vector<int>& nums) {
        int nextZero = 0; // grows towards right
        
        int nextOne = nums.size() - 1; // grows towards left
        int nextTwo = nums.size() - 1; // grows towards left
        
        while (nextZero <= nextOne) { // nextZero & nextOne grow towards each other
            
            if (nums[nextZero] == 0) {
                // trivial case: just increment
                nextZero++;
            }
            else if (nums[nextZero] == 1) {
                swap(nums[nextZero], nums[nextOne--]);
            }
            else { // tricky case
                swap(nums[nextZero], nums[nextOne]);
                swap(nums[nextOne--], nums[nextTwo--]);
            }
        }
    }
};