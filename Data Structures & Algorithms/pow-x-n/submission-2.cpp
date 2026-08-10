class Solution {
public:
    double solve(double x,int n){
        if(n==0)return 1.0;
        double temp = solve(x,n/2);
        if(n%2==0){
            return temp * temp;
        }
        return x * temp * temp;
    }
    double myPow(double x, int n) {
        double y = solve(x,abs(n));
        if(n<0)return 1.0/y;
        else return y;
    }
};
