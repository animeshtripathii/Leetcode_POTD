1class Solution {
2public:
3    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
4        bool result=true;
5        long long sum=mass;
6        sort(asteroids.begin(),asteroids.end());
7        int count=asteroids.size();
8        int n=count;
9        for(int i=0;i<n;i++){
10            if(sum>=asteroids[i]){
11                sum+=asteroids[i];
12            }
13            else{
14                return false;
15            }
16        }
17    return true;
18    }
19};