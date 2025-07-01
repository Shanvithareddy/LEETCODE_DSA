class Solution {
public:
    int INF = pow(10,4) + 1;
    int fill_min(int n, vector<int> & min_coins, vector<int> & coins){
        if(n<0) return INF;
        if(n == 0) return 0;
        if(min_coins[n] != -1) return min_coins[n];
        min_coins[n] = INF;
        for(auto c : coins){
            min_coins[n] = min(min_coins[n],1 + fill_min(n-c,min_coins,coins));
        }
        return min_coins[n];
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<int> min_coins(amount+1,-1);
        int ans = fill_min(amount,min_coins,coins);
        if(ans == INF) return -1;
        else return ans;
        
    }
};