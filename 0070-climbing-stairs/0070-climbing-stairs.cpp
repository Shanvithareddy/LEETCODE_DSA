class Solution {
public:

    int steps(int n,vector<int> & ways){
        if( ways[n] != -1) return ways[n];
        if(n==0 || n == 1) return 1;
        
        ways[n] = steps(n-1,ways)+ steps(n-2,ways);
        return ways[n];
    }

    int climbStairs(int n) {
        vector<int> ways(n+1,-1);
        return steps(n,ways);
    }
};