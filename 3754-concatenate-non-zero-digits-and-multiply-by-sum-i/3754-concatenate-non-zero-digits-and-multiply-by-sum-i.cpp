class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum=0;
        long long  rev=0;
        while(n){
            int c=n%10;
            if(c!=0){
                sum+=c;
                rev=rev*10+c;
            }
            n=n/10;
        }
        string s=to_string(rev);
        reverse(s.begin(),s.end());
        rev=stoi(s);
        long long ans=rev*sum;
        return ans;
    }
};