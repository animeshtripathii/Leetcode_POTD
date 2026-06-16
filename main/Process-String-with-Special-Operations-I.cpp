1class Solution {
2public:
3    string processStr(string s) {
4        string result="";
5        for(int i=0;i<s.length();i++){
6            char ch=s[i];
7            if(ch>='a'&&ch<='z'){
8                result+=ch;
9            }
10            else if(ch=='*' && result.size()>0){
11                result.pop_back();
12            }
13            else if(ch=='#'){
14              result+=result;
15            }
16            else{
17  reverse(result.begin(),result.end());
18            }
19        }
20        return result;
21    }
22};