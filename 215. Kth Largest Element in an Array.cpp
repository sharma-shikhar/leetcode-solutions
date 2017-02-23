class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if (k < 1 || k > nums.size())
            return -1;
        return ithStatistic(nums, 0, nums.size() - 1, nums.size() - k);
    }
    
    int ithStatistic(vector<int> & nums, int low, int high, int i) {
        int p = partition(nums, low, high);
        if (p == i)
            return nums[i];
        else if (p < i)
            return ithStatistic(nums, p + 1, high, i);
        else // i < p
            return ithStatistic(nums, low, p - 1, i);
    }
    
    int choosePivot(vector<int> & nums, int low, int high) {
        return low; // can be more intelligent like median of medians
    }
    
    int partition(vector<int> & nums, int low, int high) {
        int pivotIndex = choosePivot(nums, low, high);
        int pivot = nums[pivotIndex];
        
        swap(nums[low], nums[pivotIndex]);
        
        int cur = low + 1;
        int firstLargest = low + 1;
        
        for (; cur <= high; cur++) {
            if (nums[cur] < pivot)
                swap(nums[cur], nums[firstLargest++]);
        }
        
        swap(nums[low], nums[firstLargest - 1]);
        return firstLargest - 1;
    }
};