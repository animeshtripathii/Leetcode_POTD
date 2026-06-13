1class Solution {
2public:
3    int numRescueBoats(vector<int>& people, int limit) {
4        sort(people.begin(), people.end());
5        int l = 0, r = people.size() - 1;
6        int boats = 0;
7
8        while (l <= r) {
9            if (people[l] + people[r] <= limit) {
10                l++;  
11            }
12            r--;     
13            boats++;
14        }
15        return boats;
16    }
17};