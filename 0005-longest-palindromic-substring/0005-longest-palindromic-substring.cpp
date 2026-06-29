class Solution {
public:
    bool ispalindrome(int i, int j, string &s){
        int l = i;
        int r = j;
        while(l<=r){
            if(s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        int n = s.size();

        string ans = "";

        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                if(ispalindrome(i, j, s) && (j-i+1) > ans.size()){
                    ans = s.substr(i, j-i+1);
                }
            }
        }
        return ans;
    }
};