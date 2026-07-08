class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        long long MOD = 1e9 + 7;
        int m = s.length();
        int n = queries.size();
        
        vector<long long> pow10(m + 1, 1);
        for (int i = 1; i <= m; ++i) {
            pow10[i] = (pow10[i - 1] * 10) % MOD;
        }
        
        vector<long long> pref_sum(m + 1, 0);
        vector<long long> pref_x(m + 1, 0);
        vector<int> nz_count(m + 1, 0);
        
        for (int i = 0; i < m; ++i) {
            int digit = s[i] - '0';
            pref_sum[i + 1] = pref_sum[i] + digit;
            if (digit == 0) {
                pref_x[i + 1] = pref_x[i];
                nz_count[i + 1] = nz_count[i];
            } else {
                pref_x[i + 1] = (pref_x[i] * 10 + digit) % MOD;
                nz_count[i + 1] = nz_count[i] + 1;
            }
        }
        
        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            int l = queries[i][0];
            int r = queries[i][1];
            
            long long current_sum = pref_sum[r + 1] - pref_sum[l];
            int k = nz_count[r + 1] - nz_count[l];
            
            long long x = (pref_x[r + 1] - (pref_x[l] * pow10[k]) % MOD + MOD) % MOD;
            ans[i] = (x * current_sum) % MOD;
        }
        
        return ans;
    }
};