class Solution {
public:
    bool sumGame(string num) {
        double res = 0;
        int n = num.size();

        for(int i=0; i<n; i++){
            double sign;
            if(i < n/2) sign = 1;
            else sign = -1;

            double val;
            if(num[i] == '?') val = 4.5;
            else val = num[i] - '0';

            res += (val*sign); 
        }

        if(res != 0.0) return true;
        return false;
    }
};