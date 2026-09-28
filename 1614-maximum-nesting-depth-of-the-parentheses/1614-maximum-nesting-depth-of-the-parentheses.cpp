class Solution {
public:
    int maxDepth(string s) {
        int maxi = 0;
        int openbraces = 0;

        for(auto &ch: s){
            if(ch == '('){
                openbraces++;
                maxi = max(maxi, openbraces);
            }
            else if(ch == ')'){
                openbraces--;
            }
        }

        return maxi;
    }
};