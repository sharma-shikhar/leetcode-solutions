90. Subsets IIclass Solution {
    void _subsetsWithDup(vector<int> &nums, int index, vector<int> buf, set<vector<int>> & resultSet) {
        if (index == nums.size()) {
            sort(buf.begin(), buf.end());
            resultSet.insert(buf);
            return;
        }
        
        // exclude this element
        _subsetsWithDup(nums, index + 1, buf, resultSet);
        
        //include this element
        buf.push_back(nums[index]);
        _subsetsWithDup(nums, index + 1, buf, resultSet);
    }
    
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        set<vector<int>> resultSet;
        vector<int> buf;
        
        _subsetsWithDup(nums, 0, buf, resultSet);
        
        for (vector<int> v : resultSet)
            result.push_back(v);
        
        return result;
    }
};