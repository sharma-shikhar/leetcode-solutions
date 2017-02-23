class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minSoFar = numeric_limits<int>::max();
        int maxProfitSeen = 0;
        
        for (int i=0; i<prices.size(); i++) {
            if (prices[i] - minSoFar > maxProfitSeen)
                maxProfitSeen = prices[i] - minSoFar;
            if (prices[i] < minSoFar)
                minSoFar = prices[i];
        }
        
        return maxProfitSeen;
    }
};