class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        unordered_map<int,int>freq;
        for(int d:digits){
            freq[d]++;
        }
        int count=0;
        for(int i=100;i<1000;i+=2){
            int d1=i/100;
            int d2=(i/10)%10;
            int d3=i%10;
            int num[10]={0};
            num[d1]++;
            num[d2]++;
            num[d3]++;
            if(num[d1]<=freq[d1] && num[d2]<=freq[d2] && num[d3]<=freq[d3] ){
                count++;
            }
        }
        return count;
    }
};