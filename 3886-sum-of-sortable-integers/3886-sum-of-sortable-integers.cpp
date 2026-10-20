
class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> divisor;

        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                divisor.push_back(i);

                if (i != n / i) {
                    divisor.push_back(n / i);
                }
            }
        }

        int ans = 0;

        for (int k : divisor) {
            bool possible = true;
            int prevMax = -1;

            for (int i = 0; i < n; i += k) {
                int descent = 0;
                int mn = nums[i];
                int mx = nums[i];

                for (int j = 0; j < k; j++) {
                    int curr = i + j;
                    int next = i + (j + 1) % k;

                    if (nums[curr] > nums[next]) {
                        descent++;
                    }

                    mn = min(mn, nums[curr]);
                    mx = max(mx, nums[curr]);
                }

                if (descent > 1 || prevMax > mn) {
                    possible = false;
                    break;
                }

                prevMax = mx;
            }

            if (possible) {
                ans += k;
            }
        }

        return ans;
    }
};
