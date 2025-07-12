class Solution {
public:
    bool isHappy(int n) {
        set<int> s;
        int temp = n;
        s.insert(n);
        while(true){
            int sum = 0;
            while(temp != 0){
                sum += pow(temp%10,2);
                temp = temp /10;
            }
            if(sum == 1) return true;
            if(s.contains(sum)) return false;
            s.insert(sum);
            temp = sum;
        }
    }
};