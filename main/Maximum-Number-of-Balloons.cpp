1class Solution {
2public:
3    int maxNumberOfBalloons(string text) {
4        unordered_map<char, int> mp;
5        for(int i = 0; i < text.size(); i++){
6            mp[text[i]]++;
7        }
8        mp['l'] /= 2;
9        mp['o'] /= 2;
10        int count = min({mp['b'], mp['a'], mp['l'], mp['o'], mp['n']});
11        
12        return count;
13    }
14};