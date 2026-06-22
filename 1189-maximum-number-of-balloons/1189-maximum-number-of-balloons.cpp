class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> mp;
        for(int i = 0; i < text.size(); i++){
            mp[text[i]]++;
        }
        mp['l'] /= 2;
        mp['o'] /= 2;
        int count = min({mp['b'], mp['a'], mp['l'], mp['o'], mp['n']});
        
        return count;
    }
};