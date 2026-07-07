class Solution {
public:
    long long sumAndMultiply(int n) {
        if(n==0) return 0;
        
        string xstr = "";
        int num = n;
        long long sum = 0;
        while(num > 0){
            int ld = num%10;
            sum += ld;

            if(ld != 0) xstr+=to_string(ld);
            num /= 10;
        }

        reverse(xstr.begin(), xstr.end());

        long long x = stoll(xstr);

        return x*sum;
    }
};