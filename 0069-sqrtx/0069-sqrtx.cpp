class Solution {
public:
    int mySqrt(int x) {
        // long long int i;
        // for( i =0;i<=x;i++){
        //     if(i * i > x) break;
        // }
        // return i-1;
        long long int high = x;
        long long int low = 1;
        long long int mid = (high + low )/2;
        while(high!= low){
            if(high - low == 1) return low;
            mid = (high + low) / 2;
            if(mid * mid > x) high = mid;
            else if( mid * mid == x) return mid;
            else low = mid;
        }
        return mid;
    }
};