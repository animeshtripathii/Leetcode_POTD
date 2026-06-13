1class Solution {
2public:
3    string mapWordWeights(vector<string>& words, vector<int>& weights) {
4        string c="";
5        int n=words.size();
6        unordered_map<int,char>mp;
7        for(int i=0;i<=25;i++){
8            mp[i]='z'-i;
9        }
10    for(string w:words){
11        long long s=0;
12        for(char ch:w){
13            s+=weights[ch-'a'];
14    }
15        int rem=s%26;
16        c+=mp[rem];   
17    }
18    return c;    
19    }      
20};