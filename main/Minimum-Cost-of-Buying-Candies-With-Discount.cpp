1class Solution {
2public:
3    int minimumCost(vector<int>& cost) {
4        priority_queue<int> pq(cost.begin(), cost.end());
5        int totalCost = 0; 
6        
7        while (!pq.empty()) {
8            totalCost += pq.top();
9            pq.pop();
10            
11            if (!pq.empty()) {
12                totalCost += pq.top();
13                pq.pop();
14            }
15            
16            if (!pq.empty()) {
17                pq.pop();
18            }
19        }
20        
21        return totalCost;
22    }
23};