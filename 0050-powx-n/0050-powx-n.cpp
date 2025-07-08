class Solution {
public:
    double myPow(double x, int n) {
        // if(x == 0 || x == 1) return x;
        // if(n >=0){
        //     double pro = 1;
        //     for(double i =0;i<n;i++){
        //         pro = pro * x;
        //     }
        //     return pro;
        // }
        // else{
        //     double pro = 1;
        //     for(double i =0;i< -1 * n;i++){
        //         pro = pro / x;
        //     }
        //     return pro;
        // }
        return pow(x,n);
    }
};