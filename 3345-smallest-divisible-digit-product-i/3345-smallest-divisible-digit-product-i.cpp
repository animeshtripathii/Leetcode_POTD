class Solution {
public:
    int smallestNumber(int n, int t) {
        int c=n;
        int ans=-1;;
        bool a=true;
        while(a){
            int k=c;
             int p=1;
            while(k){
                int m=k%10;
                p*=m;
                k=k/10;
            }
            if(p%t==0){
                ans=c;
                break;
            }

            c++;
        }
        return ans;
    }
};