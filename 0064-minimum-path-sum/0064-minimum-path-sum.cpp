class Solution {
public:
    int m;
    int n;
    int INF = pow(2,30);
    int filldp(int x,int y, vector<vector<int>>&dp, vector<vector<int>>&grid){
        if(x < 0 || y < 0 || x >= m || y >= n) return INF;
        if(dp[x][y] != -1) return dp[x][y];
        dp[x][y] = min(filldp(x-1,y,dp,grid),filldp(x,y-1,dp,grid)) + grid[x][y];
        return dp[x][y];
    }
    // void print(vector<vector<int>> & grid){
    //     for(auto row: grid){
    //         for(auto el: row){
    //             cout<<el<<",";
    //         }
    //         cout<<endl;
    //     }
    // }


    int minPathSum(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        dp[0][0] = grid[0][0];
        return filldp(m-1,n-1,dp,grid);
    }
};