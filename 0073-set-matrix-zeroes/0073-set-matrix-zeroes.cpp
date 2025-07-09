class Solution {
public:

    // void print(vector<vector<int>> & matrix){
    //     for(int i=0;i<matrix.size();i++){
    //         for(int j=0;j<matrix[0].size();j++){
    //             cout<<matrix[i][j]<<",";
    //         }
    //         cout<<endl;
    //     }
    // }

    void setZeroes(vector<vector<int>>& matrix) {
        vector<int> rows;
        vector<int> columns;
        // print(matrix);
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j] == 0){
                    rows.push_back(i);
                    columns.push_back(j);
                }
            }
        }
        //clear rows
        for(auto row: rows){
            for(int j=0;j<matrix[0].size();j++){
                matrix[row][j] = 0;
            }
        }
        //clear colums
        for(auto col : columns){
            for(int i=0;i<matrix.size();i++){
                matrix[i][col] = 0;
            }
        }
        // print(matrix);
    }
};