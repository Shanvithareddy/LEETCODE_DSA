class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        uint32_t mult = pow(2,31);
        // cout<<n;
        while(mult != 0){
            ans += (n%2)*mult;
            mult = mult /2;
            n = n/2;
        }
        return ans;
    }
};