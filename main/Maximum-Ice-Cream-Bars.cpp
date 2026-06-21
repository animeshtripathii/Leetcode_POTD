1class Solution {
2public:
3    int maxIceCream(vector<int>& costs, int coins) {
4        sort(costs.begin(),costs.end());
5        int maxi=0;
6        for(int i=0;i<costs.size();i++){
7            if(coins==0){
8                break;
9            }
10            if(coins>=costs[i]){
11            coins-=costs[i];
12            maxi++;
13            }
14        }
15        return maxi;
16    }
17};