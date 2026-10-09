class Solution {
public:
    int minInsertions(string s) {
        int close = 0, open = 0;

        for(char ch : s){
            if(ch == '('){
                if(close % 2 == 1){
                    open++;
                    close--;
                }
                close += 2;
            }else{
                close--;
                if(close < 0){
                    open++;
                    close = 1;
                }
            }
        }


        return open + close;
    }
};