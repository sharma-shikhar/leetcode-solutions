class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int *ways = new int[target + 1];
        ways[0] = 1;
        
        for (int i=1; i<=target; i++) {
            int curWays = 0;
            
            for (int num : nums) {
                int index = i - num;
                if (index >= 0)
                    curWays += ways[index];
            }
            
            ways[i] = curWays;
        }
        
        int res = ways[target];
        delete[] ways;
        return res;
    }
};