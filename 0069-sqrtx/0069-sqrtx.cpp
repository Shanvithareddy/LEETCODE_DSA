class Solution {
public:
    int mySqrt(int x) {
        long long int i;
        for( i =0;i<=x;i++){
            if(i * i > x) break;
        }
        return i-1;
    }
};