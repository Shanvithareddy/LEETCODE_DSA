class Solution {
public:
    // void print(vector<vector<int>> & grid){
    //     for(auto row: grid){
    //         for(auto el: row){
    //             cout<<el<<",";
    //         }
    //         cout<<endl;
    //     }
    // }
    int m;
    int n;
    int fillCost(int x, int y, vector<vector<int>>& cost,string& word1,string& word2){
        if(cost[x][y] != -1) return cost[x][y];
        if(x == 0 || y == 0){
            cost[x][y] = max(x,y);
            return cost[x][y];
        }
        int adder = 1;
        if(word1[x-1] == word2[y-1]) adder = 0;
        cost[x][y] = min(fillCost(x,y-1,cost,word1,word2) + 1,fillCost(x-1,y,cost,word1,word2) + 1);
        // cout<< cost[x][y]<<","<<adder<<",";
        cost[x][y] = min(cost[x][y], fillCost(x-1,y-1,cost,word1,word2) + adder);
        // cout<< cost[x][y]<<endl;


        return cost[x][y];

    }
    
    int minDistance(string word1, string word2) {
        m = word1.size();
        n = word2.size();
        vector<vector<int>> cost(m+1,vector<int>(n+1,-1));
        int k = fillCost(m,n,cost,word1,word2);
        // print(cost);
        return k;
    }
};