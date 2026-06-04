1class Solution {
2public:
3    int totalWaviness(int num1, int num2) {
4        int count=0;
5    for(int i=num1;i<=num2;i++){
6        int temp=i;
7        int m=0;
8        int nums[10];
9        while(temp>0){
10            int c=temp%10;
11            nums[m++]=c;
12            temp/=10;
13        }
14        if(m<3) continue;
15        for(int j=1;j<m-1;j++){
16            if((nums[j]>nums[j-1]&&nums[j]>nums[j+1])||(nums[j]<nums[j-1]&&nums[j]<nums[j+1])){
17             count++;
18            }
19        }
20    }
21    return count;
22    }
23};