class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr = nums;
        unordered_map<int, int> mp;
        
        for(int i = 0; i < n; i++){
            mp[nums[i]] = i;
        }
        
        auto getDigitSum = [](int a) {
            int sum = 0;
            while(a) {
                sum += a % 10;
                a = a / 10;
            }
            return sum;
        };
        
        sort(nums.begin(), nums.end(), [&](int a, int b) {
            int d1 = getDigitSum(a);
            int d2 = getDigitSum(b);
            if(d1 != d2){
                return d1 < d2;
            }
            return a < b;
        });
        
        int swapCount = 0;
        
        for(int i = 0; i < n; i++) {
            int expected = nums[i];
            int original = arr[i];
            
            if(expected == original) {
                continue;
            }
            auto it = mp.find(expected);
            int expected_idx = it->second;
            swap(arr[i], arr[expected_idx]);
            mp[original] = expected_idx;
            mp[expected] = i;
            
            swapCount++;
        }
        return swapCount;
    }
};
