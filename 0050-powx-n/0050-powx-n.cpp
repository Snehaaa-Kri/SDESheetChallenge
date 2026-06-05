class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;

        long newn = n;
        if(newn<0) newn = -1*newn;

        while(newn > 0){
            if(newn%2 == 1){
                ans = ans*x;
                newn -= 1;
            }
            else{
                x = x*x;
                newn /= 2; 
            }
        }

        if(n<0) return 1/ans;
        return ans;
    }
};