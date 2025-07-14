class Solution {
public:
    int m;
    int n;
    int INF = pow(2,30);
    int filldp(int x,int y, vector<vector<int>>&dp, vector<vector<int>>&grid){
        if(x < 0 || y < 0 || x >= m || y >= n) return 0;
        if(dp[x][y] != -1) return dp[x][y];
        if(grid[x][y] == 1) {
            dp[x][y] = 0;
            return dp[x][y];
        }
        dp[x][y] = filldp(x-1,y,dp,grid) + filldp(x,y-1,dp,grid);
        return dp[x][y];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        m = obstacleGrid.size();
        n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n,-1));
        if(obstacleGrid[0][0] != 1) dp[0][0]= 1;
        return filldp(m-1,n-1,dp,obstacleGrid);
    }
};