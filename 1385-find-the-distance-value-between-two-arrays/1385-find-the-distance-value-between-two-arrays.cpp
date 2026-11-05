class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int c = 0;
        for (auto& x : arr1) {
            bool b = true;
            for (auto& y : arr2) {
                b &= (abs(x - y) > d);
            }
            c += b;
        }
        return c;
    }
};