class Solution {
public:
    vector<pair<int,int>> directions = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
    int lives(int i, int j, vector<vector<int>>& board){
        int lives = 0;
        for(auto dir : directions){
            int n_i = i + dir.first;
            int n_j = j + dir.second;
            if(n_i >=0 && n_i < board.size() && n_j >=0 && n_j < board[0].size()){
                if(board[n_i][n_j] == 1 || board[n_i][n_j] == 2) lives++;
            }
        }
        return lives;
    }
    void gameOfLife(vector<vector<int>>& board) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j] == 1){
                    int num_lives = lives(i,j,board);
                    if(num_lives != 2 && num_lives != 3) board[i][j] = 2;
                }
                else {
                    int num_lives = lives(i,j,board);
                    if(num_lives == 3) board[i][j] = 3;
                }
            }
        }
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j] == 2) board[i][j] = 0;
                else if(board[i][j] == 3) board[i][j] = 1;
            }
        }
    }
};