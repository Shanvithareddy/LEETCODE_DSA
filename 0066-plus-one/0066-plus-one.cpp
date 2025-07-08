class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        for(int i= digits.size()-1;i>=0;i--){
            digits[i] = digits[i] + carry;
            if(digits[i] > 9){
                carry = 1;
                digits[i] -= 10;
            }
            else carry = 0;
        }
        if(carry == 1){
            digits.insert(digits.begin(),1);
        }
        return digits;
    }
};