class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";

        string prevstr = countAndSay(n-1);

        int m = prevstr.size();
        string ans = "";
        int i=0;
        int cnt = 1;
        char ch = prevstr[0];

        while(i<m){
            while(i+1<m && prevstr[i+1] == prevstr[i]){
                cnt++;
                i++;
            }
            ans += to_string(cnt);
            ans += prevstr[i];
            cnt = 1;
            i++; 
        }
        return ans;
    }
};