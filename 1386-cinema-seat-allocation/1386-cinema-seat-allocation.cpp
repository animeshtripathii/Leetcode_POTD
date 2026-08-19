class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, vector<bool>> reserved_map;
        
        for (const auto& res : reservedSeats) {
            int row = res[0];
            int seat = res[1];
            
            if (reserved_map.find(row) == reserved_map.end()) {
                reserved_map[row] = vector<bool>(11, false);
            }
            
            reserved_map[row][seat] = true;
        }
        
        int total_groups = (n - reserved_map.size()) * 2;
        
        for (auto const& [row, seats] : reserved_map) {
            bool left_free = !seats[2] && !seats[3] && !seats[4] && !seats[5];
            bool right_free = !seats[6] && !seats[7] && !seats[8] && !seats[9];
            bool mid_free = !seats[4] && !seats[5] && !seats[6] && !seats[7];
            
            if (left_free && right_free) {
                total_groups += 2;
            } else if (left_free || right_free || mid_free) {
                total_groups += 1;
            }
        }
        return total_groups;
    }
};