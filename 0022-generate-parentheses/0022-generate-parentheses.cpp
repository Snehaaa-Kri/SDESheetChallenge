class Solution {
public:
    vector<string> ans;
    int N;

    // bool isValid(string str){
    //     stack<char> st;
    //     for(int i=0; i<str.size(); i++){
    //         if(str[i] =='(') st.push(str[i]);
    //         else if(st.empty()) return false;
    //         else st.pop();
    //     }
    //     return st.empty();
    // }
    bool isValid(string str){
        int cnt =0;
        for(int i=0; i<str.size(); i++){
            if(cnt<0) return false;
            if(str[i] =='(') cnt++;
            else cnt--;
        }
        return cnt==0;
    }

    void solve(string str){
        //base case
        if(str.size() > 2*N) return;
        if(str.size() == 2*N){
            if(isValid(str)){
                ans.push_back(str);
                return;
            }
        }

        str.push_back('('); //branch 1
        solve(str); //TRUST
        str.pop_back();

        str.push_back(')'); //branch 2
        solve(str); //TRUST
        str.pop_back();
    }


    vector<string> generateParenthesis(int n) {
        N = n;
        solve("");
        return ans;
    }
};