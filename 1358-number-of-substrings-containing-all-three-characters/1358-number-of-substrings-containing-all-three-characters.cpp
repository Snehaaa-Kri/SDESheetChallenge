class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int cnt = 0;
        unordered_map<char, int> ump(3);

        for(int i=0; i<n; i++){
            ump[s[i]] = i;  
            if(ump.size() == 3){
                int mini = INT_MAX;
                for(auto el : ump){
                    mini = min(mini, el.second);
                }
                cnt += (mini+1);
            }
        }
        return cnt;
    }
};