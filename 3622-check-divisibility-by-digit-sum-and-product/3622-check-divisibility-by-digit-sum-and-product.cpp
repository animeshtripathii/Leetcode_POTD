class Solution {
public:
    bool checkDivisibility(int n) {
        int temp=n;
        int sum=0;
        int product=1;
        while(temp){
            int k=temp%10;
            sum+=k;
            product*=k;
            temp/=10;
        }
        return (n%(sum+product))==0?true:false;
    }
};