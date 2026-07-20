class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int row=grid.size();
        int cols=grid[0].size();
          int n=row*cols;
          if(k==0){
            return grid;
          }

          auto reverse=[&](int x,int y){
            while(x<y){
                swap(grid[x/cols][x%cols],grid[y/cols][y%cols]);
                x++;
                y--;
            }
          };
          k=k%n;
          reverse(0,n-1);
          reverse(0,k-1);
          reverse(k,n-1);
          return grid;
            }
};