class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int total_valid_subarrays = 0;
        for (int i = 0; i < n; i++) {
            int target_count = 0;
            for (int j = i; j < n; j++) {
                if (nums[j] == target) {
                    target_count++;
                }
                int subarray_length = j - i + 1;
                if (target_count * 2 > subarray_length) {
                    total_valid_subarrays++;
                }
            }
        }
        
        return total_valid_subarrays;
    }
};