class Solution {
public:
    int reverseDegree(string s) {
        int n=s.length();
        int deg=0;
        for(int i=0;i<n;i++){
            deg+=(26-(s[i]-'a'))*(i+1);
        }
        return deg;
    }
};