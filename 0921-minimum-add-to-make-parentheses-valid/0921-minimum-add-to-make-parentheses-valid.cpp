class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans=0;
        int balance = 0;

        for(auto &ch: s){
            if(ch == '('){
                balance++;
            }
            else{
                if(balance > 0) balance--;
                else ans++;
            }
        }
        return ans+balance;
    }
};