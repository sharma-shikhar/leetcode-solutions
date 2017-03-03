class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int least = numeric_limits<int>::max();
        int secondLeast = numeric_limits<int>::max();
        
        for (int num : nums) {
            if (num <= least)
                least = num;
            else if (num <= secondLeast)
                secondLeast = num;
            else
                return true;
        }
        
        return false;
    }
};