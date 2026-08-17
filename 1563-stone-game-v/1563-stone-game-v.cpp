class Solution {
public:
vector<vector<int>>dp;
int solve(int left,int right,vector<int>&prefixSum){
    if(left>=right){
        return 0;
    }
    if(dp[left][right]!=-1){
        return dp[left][right];
    }
    int score=0;
    for(int i=left;i<=right-1;i++){
        
            int leftSum=prefixSum[i]-(left-1>=0?prefixSum[left-1]:0);
            int rightSum=prefixSum[right]-prefixSum[i];
            if (leftSum > rightSum) {
                score = max(score, rightSum + solve(i + 1, right, prefixSum));
            }
            else if (leftSum < rightSum) {
                score = max(score, leftSum + solve(left, i, prefixSum));
            } else {
                score = max(score, max(leftSum + solve(left, i, prefixSum), 
                                       rightSum + solve(i + 1, right, prefixSum)));
            }
    }
    return dp[left][right]=score;

}
    int stoneGameV(vector<int>& stoneValue) {
        int n=stoneValue.size();
        vector<int>prefixSum(n,0);
        prefixSum[0]=stoneValue[0];
        for(int i=1;i<n;i++){
            prefixSum[i]=stoneValue[i]+prefixSum[i-1];
        }
        dp.assign(n+1,vector<int>(n+1,-1));
        int l=0;
        int r=n-1;
        return solve(l,r,prefixSum);
    }
};