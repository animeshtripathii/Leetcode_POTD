class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
       string t = "1" + s + "1";
        vector<int> blocks;
        
        char curr_char = t[0];
        int count = 0;
        
        for (char c : t) {
            if (c == curr_char) {
                count++;
            } else {
                blocks.push_back(count);
                curr_char = c;
                count = 1;
            }
        }
        blocks.push_back(count);
        
        int original_ones = 0;
        for (int i = 0; i < blocks.size(); i += 2) {
            original_ones += blocks[i];
        }
        original_ones -= 2; 
        
        if (blocks.size() < 3) {
            return original_ones;
        }
        
        int max_0_block = 0;
        for (int i = 1; i < blocks.size(); i += 2) {
            max_0_block = max(max_0_block, blocks[i]);
        }
        
        int max_gain = 0; 
        
        for (int i = 2; i < (int)blocks.size() - 1; i += 2) {
            int bridge_gain = blocks[i - 1] + blocks[i + 1];
            int snipe_gain = max_0_block - blocks[i];
            max_gain = max({max_gain, bridge_gain, snipe_gain});
        }
        
        return original_ones + max_gain;
    }
};