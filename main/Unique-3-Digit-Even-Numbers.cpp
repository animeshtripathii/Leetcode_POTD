1class Solution {
2public:
3    int totalNumbers(vector<int>& digits) {
4        set<int>st;
5        int n=digits.size();
6        for(int i=0;i<n;i++){
7            if(digits[i]==0) continue;
8            for(int j=0;j<n;j++){
9                if(i==j) continue;
10                for(int k=0;k<n;k++){
11                    if(k==i||k==j) continue;
12                   if(digits[k]%2!=0) continue;
13                   int num=digits[i]*1000+digits[j]*100+digits[k]*10;
14                           st.insert(num);
15                }
16            }
17  
18        }
19        return st.size();
20    }
21};