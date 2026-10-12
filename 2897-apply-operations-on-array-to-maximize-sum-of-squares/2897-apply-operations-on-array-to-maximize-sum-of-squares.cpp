class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        vector<int> count(32, 0);
        int MOD = 1e9 + 7;
        long long result = 0;
        for(int n : nums){
            for(int i = 0; i < 31; i++){
                if(n & (1 << i)){
                    count[i]++;
                }
            }
        }
        while(k--){
            long long c = 0;
            for(int i = 0; i < 31; i++){
                if(count[i] > 0){
                    count[i]--;
                    c = (c | (1LL << i));
                }
            }
            result = (result + (c * c) % MOD) % MOD;
        }
        return static_cast<int>(result);
    }
};
