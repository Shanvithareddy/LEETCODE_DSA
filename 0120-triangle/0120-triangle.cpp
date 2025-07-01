class Solution {
public:
    int INF = pow(10,4) +1;
    int fill_mins(int i, int row, vector<vector<int>> & triangle, vector<vector<int>> & mins){
        if(i > row) return INF;
        if(row >= triangle.size()) return 0;
        if(mins[row][i] != INF) return mins[row][i];
        mins[row][i] = triangle[row][i] + min(fill_mins(i,row+1,triangle,mins),fill_mins(i+1,row+1,triangle,mins));
        return mins[row][i];
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int row = triangle.size();
        vector<vector<int>> mins(row,vector<int>(row,INF));
        
        return fill_mins(0,0,triangle,mins);
    }
};