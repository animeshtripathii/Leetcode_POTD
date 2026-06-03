1class Solution {
2public:
3    int calFinishTime(vector<int>& ls,vector<int>& ld,vector<int>& ws,vector<int>& wd) {
4
5        int mini = INT_MAX;
6
7        for (int i = 0; i < ls.size(); i++) {
8            mini = min(mini, ls[i] + ld[i]);
9        }
10
11        int ans = INT_MAX;
12
13        for (int i = 0; i < ws.size(); i++) {
14            ans = min(ans,max(mini, ws[i]) + wd[i]);
15        }
16
17        return ans;
18    }
19    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
20        return min(
21            calFinishTime(landStartTime,landDuration,waterStartTime,waterDuration),
22            calFinishTime(waterStartTime,waterDuration,landStartTime,landDuration)
23        );
24    }
25};