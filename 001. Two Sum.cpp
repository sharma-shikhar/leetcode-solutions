class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        vector<int> result;
        
        // assuming distinct elements
        
        for (int i=0; i<nums.size(); i++) {
            
            int complement = target - nums[i];
            
            if (m.find(complement) != m.end()) {
                result.push_back(m[complement]);
                result.push_back(i);
                return result;
            }
            
            m[nums[i]] = i;
        }
        
        return result;
    }
};