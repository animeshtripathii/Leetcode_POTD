class Solution {
    public int maxSubarrayLength(int[] nums, int k) {
        int n = nums.length;
        HashMap<Integer, Integer> mp = new HashMap<>();
        int i = 0;
        int j = 0;
        int maxLen = 0; 
        
        while (j < n) {
            mp.put(nums[j], mp.getOrDefault(nums[j], 0) + 1);
            
            while (mp.get(nums[j]) > k) {
                mp.put(nums[i], mp.get(nums[i]) - 1);
                i++;
            }
            
            maxLen = Math.max(maxLen, j - i + 1);
            j++;
        }
        
        return maxLen;
    }
}