class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        auto comp = [] (pair<int, int> & p1, pair<int, int> & p2) -> bool {
            return p1.first < p2.first;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> maxHeap(comp);
        
        for (int i=0; i<nums.size(); i++) {
            maxHeap.push(make_pair(nums[i], i));
        }
        
        vector<string> ranks(nums.size(), "");
        int rank = 1;
        
        while (!maxHeap.empty()) {
            pair<int, int> p = maxHeap.top(); maxHeap.pop();
            int num = p.first;
            int index = p.second;
            
            if (rank == 1) ranks[index] = "Gold Medal";
            else if (rank == 2) ranks[index] = "Silver Medal";
            else if (rank == 3) ranks[index] = "Bronze Medal";
            else ranks[index] = to_string(rank);
            rank++;
        }
        
        return ranks;
    }
};