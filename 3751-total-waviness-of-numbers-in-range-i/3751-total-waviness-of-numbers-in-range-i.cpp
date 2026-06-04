class Solution {
public:
    int getwaviness(string &s){
        if(s.size() < 3) return 0;
        int peaks = 0, valley = 0;

        for(int i=1; i<s.size()-1; i++){
            if(s[i] > s[i-1] && s[i] > s[i+1]) peaks++;
            else if(s[i] < s[i-1] && s[i] < s[i+1]) valley++;
        }
        return peaks+valley;
    }
    int totalWaviness(int num1, int num2) {
        int ans = 0;
        string s = "";
        for(int i=num1; i<=num2; i++){
            s += to_string(i);

            ans += getwaviness(s);
            s.clear();
        }
        return ans;
    }
};