class Solution {
public:
int dp[201][201][201];
int MOD=1e9 + 7;
int gcd(int a,int b){
    if(b==0){
        return a;
    }
    return gcd(b,a%b);
}
int solve(vector<int>& nums,int i,int first,int second){
    if(i==nums.size()){
        return (first==second)&&(first!=0 &&second!=0)?1:0;
    }
    if(dp[i][first][second]!=-1){
        return dp[i][first][second];
    }
    int skip=solve(nums,i+1,first,second);
    int take1=solve(nums,i+1,gcd(first,nums[i]),second);
    int take2=solve(nums,i+1,first,gcd(second,nums[i]));
    return dp[i][first][second]=(0LL+skip+take1+take2)%MOD;
}
    int subsequencePairCount(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(nums,0,0,0);
    }
};