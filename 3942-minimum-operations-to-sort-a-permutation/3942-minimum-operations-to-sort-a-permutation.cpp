class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        if(n<=1) return 0;
        vector<int>a=nums;
        int zd=-1;
        for(int i=0;i<n;i++){
            if(a[i]==0){
                zd=i;
                break;
            }
        }
        bool in=true;
        for(int i=0;i<n;i++){
            if(a[(zd+i)%n]!=i){
                in=false;
                break;
            }
        }
        if(in){
            if(zd==0) return 0;
         int op1=zd;
            int op2=2+(n-zd);
        return min(op1,op2);
    }
        bool id=true;
        for(int i=0;i<n;i++){
            int ev=(i==0)?0:n-i;
            if(a[(zd+i)%n]!=ev){
                id=false;
                break;
            }
        }
        if(id){
            int c1=n-zd;
            int c2=((zd+1)%n)+1;
        return min(c1,c2);
    }
        return -1;
    }
};