class Solution {
public:
    string processStr(string s) {
        string curr = "";

        for(auto ch: s){
            if(ch == '*'){ if(curr.size()>0) curr.pop_back();}
            else if(ch == '#') curr += curr;
            else if(ch == '%') reverse(curr.begin(), curr.end());
            else curr += ch;   
        }
        return curr;
    }
};