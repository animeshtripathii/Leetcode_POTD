class Solution {
public:
int n;
int solve(int i,vector<int>& stone, vector<int>&dp){
    if(i>=n){
        return 0;
    }
    if(dp[i]!=-1){
        return dp[i];
    }
    int result=stone[i]-solve(i+1,stone,dp);
    if(i+1<n)
    result=max(result,stone[i]+stone[i+1]-solve(i+2,stone,dp));
    if(i+2<n)
    result=max(result,stone[i]+stone[i+1]+stone[i+2]-solve(i+3,stone,dp));
    return dp[i]=result;
}
    string stoneGameIII(vector<int>& stone) {
      n=stone.size();
      vector<int>dp(n+1,-1);
      int diff=solve(0,stone,dp);
      if(diff>0){
        return "Alice";
      }
      else if(diff<0){
        return "Bob";
      }
      return "Tie";
    }
};