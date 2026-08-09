class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        int i=n-1;
        int j=m-1;
        int rightMatched=0;
        vector<int>rightHandSideMatched(n,0);
        while(i>=0){
            if(j>=0 && word1[i]==word2[j]){
                rightMatched++;
                j--;
            }
            rightHandSideMatched[i]=rightMatched;
            i--;
        }
        vector<int>ans;
        bool canChange=true;
        i=0;
        j=0;
        while(i<n && j<m){
            if(word1[i]==word2[j]){
                ans.push_back(i);
                j++;
            }
            else if(canChange && i+1<n && rightHandSideMatched[i+1]>=m-j-1){
                ans.push_back(i);
                canChange=false;
                j++;
            }
            i++;
        }
        return j==m?ans:vector<int>();
    }
};