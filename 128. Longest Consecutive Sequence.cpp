class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() < 2)
            return nums.size();
            
        unordered_set<int> m;
        for (int num : nums)
            m.insert(num);
        
        int maxSeq = 1;
        
        for (int num : nums) {
            if (m.find(num + 1) == m.end()) {
                int count = 1;
                int pred = num - 1;
                while (m.find(pred) != m.end()) {
                    pred--;
                    count++;
                }
                if (count > maxSeq)
                    maxSeq = count;
            }
        }
        return maxSeq;
        
    }
};