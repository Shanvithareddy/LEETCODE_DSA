class Solution {
public:
    vector<pair<int,int>> dir = {{-1,0},{1,0},{0,1},{0,-1}};
    int m;int n;
    void dfs(int x,int y,vector<vector<int>>&visited, vector<vector<char>>& grid){
        if(visited[x][y] == 1) return;
        visited[x][y] = 1;
        for(auto d : dir){
            int n_x = x+d.first;
            int n_y = y + d.second;
            if(n_x >= 0 && n_x < m && n_y >=0 && n_y < n){
                if(grid[n_x][n_y] == '1') dfs(n_x,n_y,visited,grid);
            }
        }
        return;
        
    }
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int num = 0;
        vector<vector<int>> visited(m,vector<int>(n));
        for(int i =0;i<m;i++){
            for(int j =0;j<n;j++){
                if(grid[i][j] == '0') continue;
                if(visited[i][j] == 0){
                    dfs(i,j,visited,grid);
                    num++;
                }
            }
        }
        return num;
    }
};