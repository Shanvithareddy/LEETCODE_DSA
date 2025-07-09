class Solution {
public:
    // bool check(int i, int j, vector<vector<char>>& board){
    //     vector<int> checked(10,0);
    //     for(int x =i;x<i+3;x++){
    //         for(int y = j;y<j+3;y++){
    //             if(checked[board[x][y]] == 1) return false;
    //             checked[board[x][y]] = 1;
    //         }
    //     }
    // }


    bool isValidSudoku(vector<vector<char>>& board) {
        //check rows
        for(auto row:board){
            vector<int> checked(10,0);
            for(auto el : row){
                if(el == '.') continue;
                // cout<<el<<"...";
                // cout<<int(el)<<"...";
                if(checked[int(el - '0')] == 1) {
                    // cout<<"checked in row";
                    return false;
                }
                checked[int(el - '0')] = 1;
            }
        }
        //check colums
        for(int j=0;j<9;j++){
            vector<int> checked(10,0);
            for(int i=0;i<9;i++){
                if(board[i][j] == '.') continue;
                if(checked[int(board[i][j] - '0')]==1) {
                    // cout<<"checked in coulumn";
                    return false;
                }
                checked[int(board[i][j] - '0')] = 1;
            }
        }
        //check squares
        for(int i=0;i<9;i = i+3){
            for(int j=0;j<9;j = j+3){
                // cout<<"here\n";
                vector<int> checked(10,0);
                for(int x =i;x<i+3;x++){
                    for(int y = j;y<j+3;y++){
                        if(board[x][y] == '.') continue;
                        if(checked[int(board[x][y] - '0')] == 1) {
                            // cout<<"checked in sqaure";
                            return false;
                        }
                        checked[int(board[x][y] - '0')] = 1;
                    }
                }
            }
        }
        return true;
    }
};