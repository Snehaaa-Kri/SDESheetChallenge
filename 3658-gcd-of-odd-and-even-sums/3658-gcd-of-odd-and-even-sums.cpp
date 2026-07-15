class Solution {
public:
    // int getgcd(int a, int b){
    //     if(b==0) return a;

    //     return gcd(b, a%b);
    // }
    int gcdOfOddEvenSums(int n) {
        int oddsum = 0, evensum = 0;
        for(int i=1; i<=2*n; i++){
            if(i%2 == 0) evensum += i;
            else oddsum += i;
        }

        return gcd(oddsum, evensum);
    }
};