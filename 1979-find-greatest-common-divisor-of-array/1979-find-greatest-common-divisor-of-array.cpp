class Solution {
public:
    int gcd(int mini, int maxi) {
        if (maxi == 0) return mini;
        return gcd(maxi, mini % maxi);
    }

    int findGCD(vector<int>& nums) {
        int maxi = *max_element(nums.begin(), nums.end());
        int mini = *min_element(nums.begin(), nums.end());
        return gcd(mini, maxi);
    }
};
