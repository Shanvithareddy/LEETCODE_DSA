class Solution {
public:
    vector<pair<int,int>> dir = {{-1,0},{1,0},{0,1},{0,-1}};
    int m;int n;
    // void print( vector<vector<int>> & grid){
    //     for(auto row : grid){
    //         for(auto el: row){
    //             cout<<el<<",";
    //         }
    //         cout<<endl;
    //     }
    //     return;
    // }
    bool dfs(int x,int y,vector<vector<int>>&visited, vector<vector<char>>& grid,int k){
       
        bool is_end = false;
        if(x == 0 || x == m-1 || y == 0 || y == n-1) is_end = true;
        if(visited[x][y] == k) return is_end;
        visited[x][y] = k;
        for(auto d : dir){
            int n_x = x+d.first;
            int n_y = y + d.second;
            if(n_x >= 0 && n_x < m && n_y >=0 && n_y < n){
                if(grid[n_x][n_y] == 'O') {
                    if( n_x == 0 || n_x == m-1 || n_y == 0 || n_y == n-1) is_end = true;
                    bool temp_is_end = dfs(n_x,n_y,visited,grid,k);
                    if(temp_is_end) is_end = true;
                }
            }
        }
        return is_end;
        
    }
    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();
        vector<vector<int>> visited(m,vector<int>(n));
        int k = 1;
        vector<int> captured;
        for(int i =0;i<m;i++){
            for(int j =0;j<n;j++){
                if(board[i][j] != 'O') continue;
                if(visited[i][j] == 0){
                    bool is_end = dfs(i,j,visited,board,k);
                    if(is_end != true) captured.push_back(k);
                    k++;
                }
            }
        }
        // print(board);
        // print(visited);
        // cout<<captured.size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                for(auto cap : captured){
                    if(visited[i][j] == cap) board[i][j] = 'X';

                }
            }
        }
        return;

    }
};