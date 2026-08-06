class Solution {
public:
    int getprod(int n){
        int prod = 1;
        while(n>0){
            prod *= (n%10);
            n /= 10;

            if(prod == 0) break;
        }

        return prod;
    }
    
    int smallestNumber(int n, int t) {
        for(int i = n; ;i++){
            if(getprod(i) % t == 0) return i;
        }
        return -1;
    }
};