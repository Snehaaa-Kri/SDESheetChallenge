class Solution {
public:
    int maxDepth(string s) {
        int maxi = 0;
        int openbraces = 0;
        stack<char> st;

        for(auto &ch: s){
            if(ch == '('){
                openbraces++;
                maxi = max(maxi, openbraces);
                st.push(ch);
            }
            else if(!st.empty() && st.top() == '(' && ch == ')'){
                st.pop();
                openbraces--;
            }
        }

        return maxi;
    }
};