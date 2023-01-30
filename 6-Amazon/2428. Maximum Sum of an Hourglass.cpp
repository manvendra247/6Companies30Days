class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int hourglass = 0;
        int maxhr = INT_MIN;
        for(int i=2;i<grid.size();i++){
            hourglass = grid[i-2][0]+grid[i-2][1]+grid[i-2][2]+ grid[i-1][1] +grid[i][0]+grid[i][1]+grid[i][2];
            maxhr = max(maxhr,hourglass);
            for(int j=3;j<grid[0].size();j++){
                hourglass-=grid[i-2][j-3]+grid[i][j-3] + grid[i-1][j-2];
                hourglass += grid[i-2][j]+grid[i][j] + grid[i-1][j-1];
                maxhr= max(maxhr,hourglass);
            }
        }
        return maxhr;
    }
};