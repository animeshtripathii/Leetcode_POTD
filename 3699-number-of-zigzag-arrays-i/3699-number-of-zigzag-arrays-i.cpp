class Solution {
public:
    static constexpr int MOD = 1000000007;

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;

        vector<int> up(m + 2), down(m + 2);

        for (int v = 1; v <= m; ++v) {
            up[v] = v - 1;
            down[v] = m - v;
        }

        for (int len = 3; len <= n; ++len) {
            vector<int> pref(m + 2), suff(m + 3);

            for (int i = 1; i <= m; ++i) {
                pref[i] = pref[i - 1] + down[i];
                if (pref[i] >= MOD) pref[i] -= MOD;
            }

            for (int i = m; i >= 1; --i) {
                suff[i] = suff[i + 1] + up[i];
                if (suff[i] >= MOD) suff[i] -= MOD;
            }

            vector<int> newUp(m + 2), newDown(m + 2);

            for (int v = 1; v <= m; ++v) {
                newUp[v] = pref[v - 1];
                newDown[v] = suff[v + 1];
            }

            up.swap(newUp);
            down.swap(newDown);
        }

        long long ans = 0;
        for (int v = 1; v <= m; ++v) {
            ans = (ans + up[v] + down[v]) % MOD;
        }

        return (int)ans;
    }
};