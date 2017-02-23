class Solution {
public:
    void getSubsets(vector<int> & nums, int index, vector<int> & buf, vector<vector<int>> & result) {
        if (index >= nums.size()) {
            result.push_back(buf);
            return;
        }
        
        // exclude this element
        getSubsets(nums, index + 1, buf, result);
        
        // include this element
        buf.push_back(nums[index]);
        getSubsets(nums, index + 1, buf, result);
        buf.pop_back();
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> buf;
        getSubsets(nums, 0, buf, result);
        return result;
    }
};