class Solution {
private:
    int findFirst(const vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        int first_idx = -1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                first_idx = mid;
                high = mid - 1; 
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return first_idx;
    }

    int findLast(const vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        int last_idx = -1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                last_idx = mid;
                low = mid + 1; 
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return last_idx;
    }

public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int start = findFirst(nums, target);
        if (start == -1) return {}; 
        int end = findLast(nums, target);
        vector<int> result;
        for (int i = start; i <= end; ++i) {
            result.push_back(i);
        }
        
        return result;
    }
};
