class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        
        for (int i=0; i<(signed int)nums.size()-2; i++) {
            
            if (i == 0 || nums[i] > nums[i-1]) {
                int low = i + 1;
                int high = nums.size() - 1;
                
                while (low < high) {
                    int sum = nums[i] + nums[low] + nums[high];
                    if (sum == 0) {
                        vector<int> v = {nums[i], nums[low], nums[high]};
                        result.push_back(v);
                        
                        int curLow = low;
                        while (low < high && nums[low] == nums[curLow])
                            low++;
                        
                        int curHigh = high;
                        while (low < high && nums[high] == nums[curHigh])
                            high--;
                    }
                    else if (sum < 0) {
                        int curLow = low;
                        while (low < high && nums[low] == nums[curLow])
                            low++;
                    }
                    else {
                        int curHigh = high;
                        while (low < high && nums[high] == nums[curHigh])
                            high--;
                    }
                }
            }
        }
        
        return result;
        
    }
};class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        
        for (int i=0; i<(signed int)nums.size()-2; i++) {
            
            if (i == 0 || nums[i] > nums[i-1]) {
                int low = i + 1;
                int high = nums.size() - 1;
                
                while (low < high) {
                    int sum = nums[i] + nums[low] + nums[high];
                    if (sum == 0) {
                        vector<int> v = {nums[i], nums[low], nums[high]};
                        result.push_back(v);
                        
                        int curLow = low;
                        while (low < high && nums[low] == nums[curLow]) // to avoid duplicates
                            low++;
                        
                        int curHigh = high;
                        while (low < high && nums[high] == nums[curHigh]) // to avoid duplicates
                            high--;
                    }
                    else if (sum < 0) {
                        int curLow = low;
                        while (low < high && nums[low] == nums[curLow]) // to avoid duplicates
                            low++;
                    }
                    else {
                        int curHigh = high;
                        while (low < high && nums[high] == nums[curHigh]) // to avoid duplicates
                            high--;
                    }
                }
            }
        }
        
        return result;
        
    }
};