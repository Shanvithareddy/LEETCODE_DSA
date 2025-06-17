class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascal;
        for(int i=0;i<numRows;i++){
            vector<int> row(i+1,0);
            for(int j=0;j<i+1;j++){
                if(j==0||j==i){
                    row[j] = 1;
                }
                else{
                    row[j] = pascal[i-1][j-1]+pascal[i-1][j];
                }
            }
            pascal.push_back(row);
        }
        return pascal;
    }
};